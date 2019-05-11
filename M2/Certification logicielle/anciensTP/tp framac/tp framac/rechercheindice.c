/*@ requires \valid(t+(0..n-1)) && n > 0;
    behavior success: 
    assumes \exists integer i; 0<=i<n ==> t[i] == elem;
    ensures 0 <= \result < n && t[\result] == elem;
    behavior failure:
    assumes \forall integer i; 0<=i<n ==> t[i] != elem;
    ensures \result == -1;
*/
int rechercheindice(int t[], int n, int elem) {
	int res = -1;
  /*@ loop invariant 0 <= i <= n &&
      \forall integer j; 0 <= j < i ==> t[j] != elem;
      loop variant n - i;
  */
  
  for (int i = 0; i < n; i++) {
    if(t[i] == elem) {
      return i;
    }
  }
  return res;
}
