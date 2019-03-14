
import java.util.stream.IntStream;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.lang.Thread;
import java.lang.Runnable;

import oracle.kv.*;
import oracle.kv.stats.*;

public class Exo2 {

    private final KVStore store;
    final Key counterKey = Key.createKey("counter2");

    /**
     * Runs Init
     */
    public static void main(String args[]) {
        try {
            Exo2 a = new Exo2(args);
            a.go();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Parses command line args and opens the KVStore.
     */
    private Exo2(String[] argv) {

        String storeName = "kvstore";
        String hostName = "localhost";
        String hostPort = "5000";

        final int nArgs = argv.length;
        int argc = 0;

        while (argc < nArgs) {
            final String thisArg = argv[argc++];

            if (thisArg.equals("-store")) {
                if (argc < nArgs) {
                    storeName = argv[argc++];
                } else {
                    usage("-store requires an argument");
                }
            } else if (thisArg.equals("-host")) {
                if (argc < nArgs) {
                    hostName = argv[argc++];
                } else {
                    usage("-host requires an argument");
                }
            } else if (thisArg.equals("-port")) {
                if (argc < nArgs) {
                    hostPort = argv[argc++];
                } else {
                    usage("-port requires an argument");
                }
            } else {
                usage("Unknown argument: " + thisArg);
            }
        }

        store = KVStoreFactory.getStore(new KVStoreConfig(storeName, hostName + ":" + hostPort));
        for (int c = 1; c < 11; c++) {
            String cat = "C" + c;
            int begin = ((c - 1) * 20) + 1;
            int end = (c * 20) + 1;
            for (int p = begin; p < end; p++) {
                store.putIfAbsent(Key.createKey(cat, "P" + p), Value.createValue("0".getBytes()));
            }
        }
        store.putIfAbsent(counterKey, Value.createValue("0".getBytes()));
    }

    int updateCounter() {
        int counter = 0;
        for (int c = 1; c < 11; c++) {
            String cat = "C" + c;
            int begin = ((c - 1) * 20) + 1;
            int end = (c * 20) + 1;
            for (int p = begin; p < end; p++) {
                counter += getOrDefault(cat, "P" + p);
            }
        }
        String res = "" + counter;
        store.put(counterKey, Value.createValue(res.getBytes()));
        return counter;
    }

    int getCounter() {
        ValueVersion vv = store.get(counterKey);
        if (vv == null) {
            store.put(counterKey, Value.createValue("0".getBytes()));
            return 0;
        }
        return Integer.parseInt(new String(vv.getValue().getValue()));
    }

    private void usage(String message) {
        System.out.println("\n" + message + "\n");
        System.out.println("usage: " + getClass().getName());
        System.out.println("\t-store <instance name> (default: kvstore) " + "-host <host name> (default: localhost) "
                + "-port <port number> (default: 5000)");
        System.exit(1);
    }

    int getOrDefault(String cat, String prod) {
        return getOrDefault(cat, prod, 0);
    }

    int getOrDefault(String cat, String prod, int defaultValue) {
        Key k = Key.createKey(cat, prod);
        ValueVersion version = store.get(k);
        int value = version == null ? defaultValue : Integer.valueOf(new String(version.getValue().getValue()));
        return value;
    }

    void increment(String cat, String prod) {
        Key k = Key.createKey(cat, prod);
        Version put;
        do {
            ValueVersion version = store.get(k);
            int value = getOrDefault(cat, prod);
            String res = "" + (value + 1);
            Version matchVersion = version == null ? null : version.getVersion();
            put = store.putIfVersion(k, Value.createValue(res.getBytes()), matchVersion);
        } while (put == null);
    }

    Operation createPutIf(String cat, String prod, int value, Version matchVersion) {
        Key key = Key.createKey(cat, prod);
        Value valueToPut = Value.createValue(("" + value).getBytes());
        return store.getOperationFactory().createPutIfVersion(key, valueToPut, matchVersion,
                ReturnValueVersion.Choice.NONE, true);
    }

    int valueVersionToInt(ValueVersion vv) {
        return Integer.valueOf(new String(vv.getValue().getValue()));
    }

    /**
     * Initialisation
     */
    void go() throws Exception {

        System.out.println("Initialisation...");

        System.out.println("Compteur avant : " + getCounter());

        IntStream.range(0, 2).parallel().forEach(n -> {
            String cat = "C1", prod;
            Key k1 = Key.createKey(cat);
            for (int i = 0; i < 1000; i++) {
                Map<Key, ValueVersion> versionMap = store.multiGet(k1, null, null);
                List<Operation> listOp = new ArrayList<>();
                int max = -1;
                for (int j = 1; j < 6; j++) {
                    prod = "P" + j;
                    Key key = Key.createKey(cat, prod);
                    int current = valueVersionToInt(versionMap.get(key));
                    if (max < current) {
                        max = current;
                    }
                }
                for (int j = 1; j < 6; j++) {
                    prod = "P" + j;
                    Key key = Key.createKey(cat, prod);
                    ValueVersion version = versionMap.get(key);
                    int value = max + 1;
                    listOp.add(createPutIf(cat, prod, value, version.getVersion()));
                }

                try {
                    store.execute(listOp);
                } catch (oracle.kv.OperationExecutionException e) {
                    i--;
                }
            }
        });

        System.out.println("Compteur après : " + updateCounter());
        System.out.println("Fin d'initialisation");
        store.close();

    }
}
