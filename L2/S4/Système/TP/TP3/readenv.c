#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void printenv(char *var);

int main(int argc, char *argv[]){//on lit les variables d'environnement HOME LANG PATH PWD SHELL et USER
	printenv("HOME");
	printenv("LANG");
	printenv("PATH");
	printenv("PWD");
	printenv("SHELL");
	printenv("USER");
	return 0;
}

void printenv(char *var){
	char *str = getenv(var);
	if(str != NULL) printf("%s = %s\n",var,str);
	else printf("%s : variable not found\n",var);
}