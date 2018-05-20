#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "string_op.h"
#include "word_array.h"
#include "word_dict.h"
#include "wildcard.h"

#define BUFSIZE 32

void clean_newline(char *buf, size_t size) {
	for(size_t i=0; i<size; i++){
		if(buf[i] == '\n'){
			buf[i] = '\0';
			return;
		}
	}
}

int main(int argc, char *argv[]){
	char buf[BUFSIZE];
	struct timeval begin;
	struct timeval end;
	struct word_array anagArray;
	struct word_array anagDict;
	struct word_array array;
	word_array_create(&array);
	word_array_read_file(&array,"dictionnaire.txt");
	word_array_sort(&array);

	struct word_dict dict;
	word_dict_create(&dict);
	word_dict_fill_with_array(&dict,&array);

	printf("Readed %zu words in array, %zu in dict\n",array.size,dict.count);

	printf("Please, enter a word or sequence of letters :\n");

	for (;;) {
		printf("> ");
		fgets(buf, BUFSIZE, stdin);
		clean_newline(buf, BUFSIZE);

		if(strcmp(buf,"") == 0) {
			break;
		}

		
		if(gettimeofday(&begin, NULL) == -1){
			fprintf(stderr, "Error : can't get time of day.\n");
		}

		printf("\n\n===============WITH ARRAY==============\n");

		word_array_create(&anagArray);
		word_array_search_anagrams_wildcard(&array, buf, &anagArray);
		word_array_sort(&anagArray);
		word_array_print(&anagArray);
		printf("%zu anagrams found\n",anagArray.size);
		word_array_destroy(&anagArray);

		if(gettimeofday(&end, NULL) == -1){
			fprintf(stderr, "Error : can't get time of day.\n");
		}

		printf("Execution time for word_array : %zu µs\n",((end.tv_sec - begin.tv_sec) * 1000000) + (end.tv_usec - begin.tv_usec));

		if(gettimeofday(&begin, NULL) == -1){
			fprintf(stderr, "Error : can't get time of day.\n");
		}

		printf("\n\n===============WITH DICT===============\n");

		word_array_create(&anagDict);
		word_dict_search_anagrams_wildcard(&dict, buf, &anagDict);
		word_array_sort(&anagDict);
		word_array_print(&anagDict);
		printf("%zu anagrams found\n",anagDict.size); 
		word_array_destroy(&anagDict);

		if(gettimeofday(&end, NULL) == -1){
			fprintf(stderr, "Error : can't get time of day.\n");
		}

		printf("Execution time for word_dict : %zu µs\n",((end.tv_sec - begin.tv_sec) * 1000000) + (end.tv_usec - begin.tv_usec));
	}
	word_array_destroy(&array);
	word_dict_destroy(&dict);
	
	return EXIT_SUCCESS;
}
