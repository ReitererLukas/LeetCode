#include <stdio.h>
#include <cmath>

using namespace std;

int reverseSum(int x)
{
  int rev = 0;
  int posMax = (pow(2, 31) - 1) / 10;
  while (x != 0)
  {
    if (posMax < rev)
      return 0;
    rev *= 10;
    rev += x % 10;
    x /= 10;
  }

  return rev;
}

bool sol_1(int x)
{
  if (x < 0)
    return false;
  else
  {
    int rev = reverseSum(x);
    if(rev == x)
      return true;
    return false;
  }
}

int main()
{
  int x = 10;
  printf("%d", sol_1(x));
  return 0;
}