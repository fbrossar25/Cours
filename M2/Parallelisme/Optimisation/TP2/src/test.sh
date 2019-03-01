#!/bin/sh
list="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 31 32 64 128"
rm perf-*.csv
for n in $list
do
    echo "1024x1024 normal $n threads"
	./MatrixProduct1024 -k 0 -nt $n -q

    echo "4096x4096 normal $n threads"
	./MatrixProduct4096 -k 0 -nt $n -q

    echo "8192x8192 normal $n threads"
	./MatrixProduct8192 -k 0 -nt $n -q

    echo "1024x1024 BLAS $n threads"
	./MatrixProduct1024 -k 1 -nt $n -q

    echo "4096x4096 BLAS $n threads"
	./MatrixProduct4096 -k 1 -nt $n -q

    echo "8192x8192 BLAS $n threads"
	./MatrixProduct8192 -k 1 -nt $n -q
done
