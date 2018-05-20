easea sinus_it.ez
make -f sinus_it.mak
./sinus_it
make -f sinus_it.mak easeaclean
gnuplot sinus_it_out.txt -p
