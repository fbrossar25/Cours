
import java.util.stream.IntStream;
import java.lang.Thread;
import java.lang.Runnable;

import oracle.kv.*;
import oracle.kv.stats.*;

/**
 * TME avec KVStore : Init
 */
public class Init {

    private final KVStore store;

    /**
     * Runs Init
     */
    public static void main(String args[]) {
        try {
            Init a = new Init(args);
            a.go();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Parses command line args and opens the KVStore.
     */
    private Init(String[] argv) {

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
        for (int i = 1; i < 101; i++)
            store.putIfAbsent(Key.createKey("P" + i), Value.createValue("0".getBytes()));
    }

    private void usage(String message) {
        System.out.println("\n" + message + "\n");
        System.out.println("usage: " + getClass().getName());
        System.out.println("\t-store <instance name> (default: kvstore) " + "-host <host name> (default: localhost) "
                + "-port <port number> (default: 5000)");
        System.exit(1);
    }

    /**
     * Initialisation
     */
    void go() throws Exception {

        System.out.println("Initialisation...");
        Key counterKey = Key.createKey("counter");
        if (store.get(counterKey) == null) {
            store.put(counterKey, Value.createValue("0".getBytes()));
        }

        System.out.println("Compteur avant : " + new String(store.get(counterKey).getValue().getValue()));

        IntStream.range(0, 2).parallel().forEach(n -> {
            for (int i = 0; i < 1000; ++i) {
                int r = 1 + (i % 100);
                Key k = Key.createKey("P" + r);
                ValueVersion version = store.get(k);
                int value = version == null ? 0 : Integer.valueOf(new String(version.getValue().getValue()));
                String res = "" + (value + 1);
                Version matchVersion = version == null ? null : version.getVersion();
                Version put = store.putIfVersion(k, Value.createValue(res.getBytes()), matchVersion);
                if (put == null) // si put refusée (écriture concurrente)
                    i--;
            }
        });

        int counter = 0;
        for (int i = 1; i < 101; ++i) {
            Key k = Key.createKey("P" + i);
            counter += Integer.valueOf(new String(store.get(k).getValue().getValue()));
        }
        String res = "" + counter;
        store.put(counterKey, Value.createValue(res.getBytes()));

        System.out.println("Compteur après : " + new String(store.get(counterKey).getValue().getValue()));
        System.out.println("Fin d'initialisation");
        store.close();

    }
}
