#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int d1;
	char ch[10];
	ch[0] = 'x';
	ch[1] = 'y';
	d1 = creat("fifi", 0666);
	if(fork() != 0){
		sleep(1);
		printf("lancement processus 1\n");
		write(d1, "AB", 2);
		sleep(2);
		write(d1, ch, 2);
		exit(0);
	}
	else{
		ch[0] = 'w'; ch[1] = 'z';
		printf("lancement processus 2\n");
		sleep(2);
		write(d1,ch,2);
		exit(0);
	}
}