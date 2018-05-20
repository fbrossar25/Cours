#include "word_array.h"
#include <stdbool.h>

#define CAPACITY 16
#define WORD_LETTERS_MAX 32

// 2.1
void word_array_create(struct word_array *self) {
	self->size = 0;
	self->capacity = CAPACITY;
	self->data = calloc(CAPACITY,sizeof(char*));
}
//2.2
void word_array_destroy(struct word_array *self) {
	if(self->data == NULL) return;
	for(size_t i=0; i<self->size; i++){
		free(self->data[i]);
	}
	free(self->data);
	self->data = NULL;
	self->size = 0;
}
//2.3
void word_array_add(struct word_array *self, const char *word) {
	if(self->size == self->capacity) {
		self->capacity *= 2;
		char **data = calloc(self->capacity,sizeof(char*));
		memcpy(data, self->data,self->size * sizeof(char*));
		free(self->data);
		self->data = data;
	}
	self->data[self->size] = string_duplicate(word);
	self->size++;
}
//2.4
void word_array_search_anagram(const struct word_array *self, const char *word, struct word_array *result) {
	for(size_t i = 0; i < self->size; i++) {
		if(string_are_anagrams(word, self->data[i])){
			word_array_add(result, self->data[i]);
		}
	}
}
//2.5
void word_array_sort(struct word_array *self) {
	// seen on qsort manpage
	int cmpstringp(const void *p1, const void *p2) {
       /* The actual arguments to this function are "pointers to
          pointers to char", but strcmp(3) arguments are "pointers
          to char", hence the following cast plus dereference */
		return strcmp(* (char * const *) p1, * (char * const *) p2);
   }
   qsort(self->data, self->size, sizeof(self->data), cmpstringp);
}
//2.6
void word_array_print(const struct word_array *self) {
	for(size_t i = 0; i < self->size; i++) {
		printf("%s\n", self->data[i]);
	}
}
//2.7
void word_array_read_file(struct word_array *self, const char *file) {
	FILE *fp = fopen(file,"r");
	if(fp == NULL) {
		fprintf(stderr, "Error : unable to open file '%s'\n",file);
		return;
	}
	char word[WORD_LETTERS_MAX];
	size_t i;
	while(fgets(word, WORD_LETTERS_MAX, fp) != NULL) {
		i = 0;
		while(word[i] != '\0'){
			if(word[i] == '\n'){
				word[i] = '\0';
			}
			i++;
		}
		word_array_add(self,word);
	}
	fclose(fp);
}