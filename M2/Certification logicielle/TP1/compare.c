/*@
requires n > 0;
requires \valid(a+(0..n-1));
requires \valid(b+(0..n-1));
ensures \result <==> \forall integer i; 0 <= i < n ==> a[i] == b[i];
*/
int compare(int a[], int b[], int n)
{
    int i = 0;
    /*@
    loop invariant \forall integer j; 0 <= j < i ==> a[j] == b[j];
    loop invariant 0 <= i <= n;
    loop variant n-i;
    */
    while(i<n && a[i]==b[i])
    {
        i++;
    }
    return i == n;
}