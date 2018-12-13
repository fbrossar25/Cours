/*@ requires \valid(t+(0..n-1)) && n > 0;
    ensures \result == 0 || \result == 1;
    ensures \result != 0 <==> \forall integer i; 0<=i<n ==> t[i] == t[n-i-1];
*/
int palindrome(int t[], int n) {
  /*@ loop invariant 0 <= i <= n && 
      \forall integer j; 0 <= j < i ==> t[j] == t[n-j-1];
      loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    if(t[i] != t[n-i-1]) {
      return 0;
    }
  }
  return 1;
}