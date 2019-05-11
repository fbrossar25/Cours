/*@
requires n > 0;
requires \valid(t+(0..n-1));
ensures \forall integer i; 0 <= i < n ==> t[i] == filler;
*/
void fillWith(int t[], int n, int filler)
{
    /*@
    loop invariant \forall integer j; 0 <= j < i ==> t[j] == filler;
    loop invariant 0 <= i <= n;
    loop variant n-i;
    */
    for(int i=0; i<n; i++)
    {
        t[i] = filler;
    }
}