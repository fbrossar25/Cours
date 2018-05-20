#include <stdio.h>
#include <stdlib.h>

int select_1(const int *data, size_t n);
int select_sorted(const int *data; size_t n; size_t k);
int select_unsorted(const int *data; size_t n; size_t k);
void swap(int *data, size_t n, size_t j);
size_t partition(int *data, size_t i, size_t j);
int select(int *data, size_t n, size_t k);
int select_partial(int *data, size_t i, size_t j, size_t k);

int main(int argc, char const *argv[])
{
	
	return 0;
}

//O(n)
//min
int select_1(const int *data, size_t n){
	int res = data[0];
	for(int i=1; i<n; i++){
		if(data[i] < res) res = data[i];
	}
	return res;
}

int select_sorted(const int *data; size_t n; size_t k){
	return data[k-1];
}

int select_unsorted(const int *data; size_t n; size_t k){
	int *sortedArray = int_array_sort(data,n);
	return select_sorted(sortedArray,n,k);
}

void swap(int *data, size_t i, size_t j){
	int save = data[i];
	data[i] = data[j];
	data[j] = save;
}

//O(n) ou n = j-i
size_t partition(int *data, size_t i, size_t j){
	size_t pivot = j;
	size_t l = i;
	for(size_t k=i; k<j; ++k){
		if(data[k] < data[pivot]){
			swap(data,k,l);
			l++;
		}
	}
	swap(data,l,j);
	return l;
}

int select(int *data, size_t n, size_t k){
	int *sortedArray = int_array_sort(data,n,k);
	return select_partial(data,0,n-1,k);
}

//n = j-i+1
//p = m - i
//C(n) = O(n) + max(C(p),C(n-p-1))
int select_partial(int *data, size_t i, size_t j, size_t k){
	size_t m = partition(data,i,j);
	if(m == k-1){
		return data[m];
	}
	if(k-1 < m){
		return select_partial(data,i,m-1,k);
	}
	return select_partial(data,m+1,j,k);
}

/*
Question 18.8 :
p = n-1 ou p = 0
C(n)= O(n) + max(C(0),C(n-1))
	= C(n-1) + O(n)
	= O(n*n)

Question 18.9 :
C(n)= O(n) + max(C(n/2),C(n/2))
	= C(n/2) + O(n)
	= O(n)
*/