/*@ requires \valid(s+(0..n-1)) && \valid(t+(0..n-1)) && n > 0;
    ensures \result == 0 || \result == 1;
    ensures \result != 0 <==> \forall integer i; 0<=i<n ==> t[i] == s[i];
*/
int compare(int s[], int t[], int n) {
  /*@ loop invariant 0 <= i <= n && 
      \forall integer j; 0 <= j < i ==> t[j] == s[j];
      loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    if(t[i] != s[i]) {
      return 0;
    }
  }
  return 1;
}