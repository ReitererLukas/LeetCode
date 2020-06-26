#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

int sol_modulo(int x)
{
  int rev = 0;
  bool neg = false;
  int posMax = (pow(2, 31)-1) / 10;
  int negMax = pow(2, 31) / 10 * -1;
  while (x != 0)
  {
    if (posMax < rev || negMax > rev)
      return 0;
    rev *= 10;
    int n = x%10;
    printf("%d\n",n);
    if(n < 0)
    {
      n *= -1;
      neg = true;
    }
      
    rev += n;
    x /= 10;
  }
  if(neg)
  {
    rev *= -1;
  }

  return rev;
}

int main()
{
  int x = -59;
  //printf("%d\n",-59%10);
  printf("%d", sol_modulo(x));
  return 0;
}