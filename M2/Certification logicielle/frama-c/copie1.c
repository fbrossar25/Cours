/*@
requires n > 0;
requires \valid(s+(0..n-1));
requires \valid(t+(0..n-1));
ensures \forall integer i; 0 <= i < n ==> s[i] == t[i];
*/
void copie1(int s[], int t[], int n)
{
    /*@
    loop invariant \forall integer j; 0 <= j < i ==> s[j] == t[j];
    loop invariant 0 <= i <= n;
    loop variant n-i;
    */
    for(int i=0; i<n; i++)
    {
        t[i] = s[i];
    }
}