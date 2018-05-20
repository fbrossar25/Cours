#include <stdio.h>
#include <stdlib.h>

//O(1)
int sorted_array_max_diff(const int *data, size_t n){
	return data[n-1] - data[0];
}

//N(o) = 2n donc C(n) = O(n)
int array_max_diff(int *data, size_t n){
	int min = data[0];
	int max = data[1];
	for(int i=2; i<n; i++){
		if(data[i] > max) max = data[i];
		if(data[i] < min) min = data[i];
	}
	return abs(min - max);
}

//O(n)
int sorted_array_min_diff(const int *data, size_t n){
	int res = abs(data[0] - data[1]);
	int calcul;
	for(int i=1; i<n-1; i++){
		calcul = abs(data[i] - data[i+1]);
		if(calcul < res) res = calcul;
	}
	return res;
}

//C(n) = n log n + n = O(n log n)
int array_min_diff(int *data, size_t n){
	int res = abs(data[0] - data[1]);
	int calcul;
	for(int i=1; i<n; i++){
		for(int j=i+1; j<n; j++){
			calcul = abs(data[i] - data[j]);
			if(calcul < res) res = calcul;
		}
	}
	return res;
	/*avec tri
	array_sort(data,n);
	return sorted_array_min_diff(data,n);
	*/
}
/*
void array_sort(int *data, size_t n){

}
*/
int main(int agrc, char **argv){
	int data[] = {1,3,5,8};
	int data2[] = {-100,50,3,1};
	printf("sorted Dmax = %d\n",sorted_array_max_diff(data,4));
	printf("unsorted Dmax = %d\n",array_max_diff(data2,4));
	printf("sorted Dmin = %d\n",sorted_array_min_diff(data,4));
	printf("unsorted Dmin = %d\n",array_min_diff(data2,4));
	return EXIT_SUCCESS;
}