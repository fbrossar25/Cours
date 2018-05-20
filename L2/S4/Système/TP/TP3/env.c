#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void printenv(char *var);

int main(int argc, char **argv, char **envp){
	int i = 0;
	while(envp[i] != NULL){//parcours toutes les variables d'environnement
		printenv(envp[i]);
		i++;
	}
	return 0;
}

void printenv(char *var){
	printf("%s = %s\n",var,getenv(var));
}