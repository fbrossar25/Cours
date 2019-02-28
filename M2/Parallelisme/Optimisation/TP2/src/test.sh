#!/bin/sh
list="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 31 32 64"
#list="15 16"
for n in $list
do
	echo "Produit 1024x1024 pour $n threads kernel 0"
    ./MatrixProduct1024 -k 0 -nt $n >> Kernel0_1024.txt
    echo "--------------\n\n\n" >> Kernel0_1024.txt
	echo "Produit 4096x4096 pour $n threads kernel 0"
    ./MatrixProduct4096 -k 0 -nt $n >> Kernel0_4096.txt
    echo "--------------\n\n\n" >> Kernel0_4096.txt
	echo "Produit 1024x1024 pour $n threads kernel BLAS"
    ./MatrixProduct1024 -k 1 -nt $n >> Kernel1_1024.txt
    echo "--------------\n\n\n" >> Kernel1_1024.txt
	echo "Produit 4096x4096 pour $n threads kernel BLAS"
    ./MatrixProduct4096 -k 1 -nt $n >> Kernel1_4096.txt
    echo "--------------\n\n\n" >> Kernel1_4096.txt
done
