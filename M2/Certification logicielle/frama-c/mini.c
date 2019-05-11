/*@
ensures \result == a || \result == b;
ensures (\result == a && a <= b) || (\result == b && b <= a);
@*/
int mini(int a, int b)
{
    return a > b ? b : a;
}
