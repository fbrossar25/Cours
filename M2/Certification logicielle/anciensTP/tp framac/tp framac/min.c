/*@ ensures \result == x || \result == y ;
      ensures \result <= x ;
      ensures \result <= y ;  
*/
int min(int x, int y)
{
  return x<y ? x : y;
}