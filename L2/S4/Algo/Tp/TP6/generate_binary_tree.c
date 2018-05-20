#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max(a,b) ((a>b)?a:b)

struct tree {
	struct tree *left;
	struct tree *right;
};

struct tree *tree_merge(struct tree *left, struct tree *right);
struct tree *tree_generate(int n);
void tree_destroy(struct tree *self);
int tree_height(const struct tree *self);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	size_t i;
	size_t sizeTab[128];
	struct tree *t;
	for(i=0; i<128; i++){
		sizeTab[i] = 0;
	}
	for(i=0; i<10000; i++){
		t = tree_generate(127);
		sizeTab[ tree_height(t) ]++;
		tree_destroy(t);
	}
	for(i=0; i<128; i++){
		printf("size : %zu, # = %zu\n",i,sizeTab[i]);
	}
	return EXIT_SUCCESS;
}

struct tree *tree_merge(struct tree *left, struct tree *right){
	struct tree *father = malloc(sizeof(struct tree));
	father->left = left;
	father->right = right;
	return father;
}

struct tree *tree_generate(int n){
	if(n <= 0){
		return NULL;
	}
	int q = rand() % n;
	return tree_merge(tree_generate(q),tree_generate(n-1-q));
}


/*
function DepthFirstTraversal(t)
	if empty(t) then
		return
	end if
	ComputePreOrder(value(t))
	for c in children(t) do
		DepthFirstTraversal(c)
	end for
	ComputePostOrder(value(t))
end function
*/
int tree_height(const struct tree *self){
	if(self == NULL){
		return 0;
	}
	int right = 0;
	int left = 0;
	if(self->right != NULL){
		right = 1 + tree_height(self->right);
	}
	if(self->left != NULL){
		left = 1 + tree_height(self->left);
	}
	return max(left,right);
}

void tree_destroy(struct tree *self){
	if(self == NULL){
		return;
	}
	if(self->left != NULL){
		tree_destroy(self->left);
	}
	if(self->right != NULL){
		tree_destroy(self->right);
	}
	free(self);
}