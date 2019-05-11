/*@
requires n > 0;
requires \valid(t+(0..n-1));
ensures \result <==> \forall integer i; 0 <= i < n ==> t[i] == 0;
*/
int allz(int t[], int n)
{
    int i= 0;
    /*@
    loop invariant \forall integer j; 0 <= j < i ==> t[j] == 0;
    loop invariant 0 <= i <= n;
    loop variant n-i;
    */
    while(i < n && t[i] == 0)
    {
        i++;
    }
    return i == n;
}