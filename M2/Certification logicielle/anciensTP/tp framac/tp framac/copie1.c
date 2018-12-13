/*@ requires \valid(s+(0..n-1)) && \valid(t+(0..n-1)) && n > 0;
    ensures \forall integer i; 0<=i<n ==> t[i] == s[i];
*/
void copie1(int s[], int t[], int n) {
  /*@ loop invariant 0 <= i <= n && 
      \forall integer j; 0 <= j < i ==> t[j] == s[j];
      loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    t[i] = s[i];
  }
}