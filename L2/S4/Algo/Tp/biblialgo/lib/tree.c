#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define max(a,b) ((a>b)?a:b)

struct tree_node {
  int value;
  struct tree_node *left;
  struct tree_node *right;
};

void tree_create(struct tree *self) {
	self->root = NULL;
}

void tree_destroy_node(struct tree_node *self){
	if(self == NULL)
	{
		return ;
	}
	if(self->left != NULL)
	{
		tree_destroy_node(self->left);
	}
	if(self->right != NULL)
	{
		tree_destroy_node(self->right);
	}
	free(self);
}

void tree_destroy(struct tree *self) {
	if(self == NULL || self->root == NULL)
	{
		return ;
	}
	tree_destroy_node(self->root);
}

bool tree_contains_node(const struct tree_node *self, int value){
	if(self == NULL)
	{
		return false;
	}
	if(self->value == value)
	{
		return true;
	}
	return tree_contains_node(self->right,value) || tree_contains_node(self->left,value);
}

bool tree_contains(const struct tree *self, int value) {
	if(self == NULL)
	{
		return false;
	}
	return tree_contains_node(self->root, value);
}

struct tree_node  *tree_insert_node(struct tree_node *self, int value){
	if(self == NULL)
	{
		struct tree_node *new = malloc(sizeof(struct tree_node));
		new->value = value;
		new->left = new->right = NULL;
		return new;
	}
	if(value < self->value)
	{
		self->left = tree_insert_node(self->left,value);
	}
	if(value > self->value)
	{
		self->right = tree_insert_node(self->right,value);
	}
	return self;
}

void tree_insert(struct tree *self, int value) {
	self->root = tree_insert_node(self->root,value);
}

struct tree_node *tree_delete_minimum(struct tree_node *self, struct tree_node **min) {
	if (self->left == NULL)
	{
		struct tree_node *right = self->right;
		self->right = NULL;
		*min = self;
		return right;
	}
	self->left = tree_delete_minimum(self->left, min);
	return self;
}

struct tree_node *tree_delete(struct tree_node *self){
	struct tree_node *left = self->left;
	struct tree_node *right = self->right;
	free(self);
	self = NULL;
	if (left == NULL && right == NULL)
	{
		return NULL;
	}
	if (left == NULL)
	{
		return right;
	}
	if (right == NULL)
	{
		return left;
	}
	right = tree_delete_minimum(right, &self);
	self->left = left; self->right = right;
	return self;
}

struct tree_node *tree_remove_node(struct tree_node *self, int value) {
	if (self == NULL)
	{
		return NULL;
	}
	if (value < self->value)
	{
		self->left = tree_remove_node(self->left, value);
		return self;
	}
	if (value > self->value)
	{
		self->right = tree_remove_node(self->right, value);
		return self;
	}
	return tree_delete(self);
}

void tree_remove(struct tree *self, int value) {
	if(self == NULL)
	{
		return ;
	}
	self->root = tree_remove_node(self->root,value);
}

bool tree_is_empty(const struct tree *self) {
  return self->root == NULL;
}

size_t tree_size_node(const struct tree_node *self){
	if(self == NULL)
	{
		return 0;
	}
	size_t res = 0;
	if(self->right != NULL)
	{
		res += 1 + tree_size_node(self->right);
	}
	if(self->left != NULL)
	{
		res += 1 + tree_size_node(self->left);
	}
	return res;
}

size_t tree_size(const struct tree *self) {
	if(self == NULL || self->root == NULL)
	{
		return 0;
	}
	return 1 + tree_size_node(self->root);
}

size_t tree_height_node(const struct tree_node *self)
{
	if(self == NULL){
		return 0;
	}
	size_t right = 0;
	size_t left = 0;
	if(self->right != NULL)
	{
		right = 1 + tree_height_node(self->right);
	}
	if(self->left != NULL)
	{
		left = 1 + tree_height_node(self->left);
	}
	return max(left,right);
}

size_t tree_height(const struct tree *self) {
	if(self == NULL || self->root == NULL){
		return 0;
	}
	return 1 + tree_height_node(self->root);
}

void tree_node_walk_pre_order(const struct tree_node *self, tree_func_t func, void *user_data){
	if(self == NULL)
	{
		return ;
	}

	func(self->value,user_data);
	tree_node_walk_pre_order(self->left, func, user_data);
	tree_node_walk_pre_order(self->right, func, user_data);
}

void tree_walk_pre_order(const struct tree *self, tree_func_t func, void *user_data)  {
	tree_node_walk_pre_order(self->root, func, user_data);
}

void tree_node_walk_in_order(const struct tree_node *self, tree_func_t func, void *user_data){
	if(self == NULL)
	{
		return ;
	}

	tree_node_walk_in_order(self->left, func, user_data);
	func(self->value, user_data);
	tree_node_walk_in_order(self->right, func, user_data);
}

void tree_walk_in_order(const struct tree *self, tree_func_t func, void *user_data) {
	tree_node_walk_in_order(self->root, func, user_data);
}

void tree_node_walk_post_order(const struct tree_node *self, tree_func_t func, void *user_data){
	if(self == NULL)
	{
		return ;
	}

	tree_node_walk_post_order(self->left, func, user_data);
	tree_node_walk_post_order(self->right, func, user_data);
	func(self->value,user_data);
}

void tree_walk_post_order(const struct tree *self, tree_func_t func, void *user_data) {
	tree_node_walk_post_order(self->root,func,user_data);
}

void tree_dump_node(const struct tree_node *self){
	if(self == NULL)
	{
		return ;
	}
	tree_dump_node(self->left);
	printf(" %d ",self->value);
	tree_dump_node(self->right);
}

void tree_dump(const struct tree *self){
	tree_dump_node(self->root);
	printf("\n");
}