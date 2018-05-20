#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 10

int main(int argc, char *argv[]){
	if(argc != 3){
		fprintf(stderr,"Need 2 args\n");
		return EXIT_FAILURE;
	}
	size_t len = strlen(argv[1]);
	if(len != strlen(argv[2])){
		fprintf(stderr,"Bad length\n");
		return 1;
	}
	char buf[BUFSIZE]; /* buffer */
	while(!feof(stdin)){
		size_t size=fread(buf,sizeof(char),BUFSIZE,stdin);
		for(size_t i=0; i<size; i++){
			char c = buf[i];
			for(size_t j=0; j<len; j++){
				if(c == argv[1][j]){
					buf[i] = argv[2][j];
					break;
				}
			}
		}
		fwrite(buf,sizeof(char),size,stdout);
	}
	printf("%s\n",buf);
	return EXIT_SUCCESS;
}