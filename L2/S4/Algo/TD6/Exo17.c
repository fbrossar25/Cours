#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//coordonée d'un vecteur creux
struct coord{
	size_t index;	//indice dans le k-uplet dans [1,k]
	double value;	//valeur de la coordonnée
};

//tableau dynamique de coordonnées
struct vector{
	size_t capacity;	//nombre d'éléments maximum du tableau
	size_t size;		//nombre d'éléments du tableau
	struct coord *data;	//tableau
};

double vector_access(const struct vector *self, size_t index);
void vector_set(struct vector *self, size_t index, double value);
void vector_add(const struct vector *v1, const struct vector *v2, struct vector *result);

int main(int agrc, char **argv){
	
	return EXIT_SUCCESS;
}

double vector_access(const struct vector *self, size_t index){
	return 0.0;
}

void vector_set(struct vector *self, size_t index, double value){

}

void vector_add(const struct vector *v1, const struct vector *v2, struct vector *result){
	
}