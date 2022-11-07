#include <stdio.h>

using namespace std;

int maximum69Number(int num) {
  int m = 1000;
  int res = 0;
  
  while(m > 0) {
    int tmp = num/m;
    if(tmp == 6) {
      res = (res*10)+9;
      return (res*m)+(num%m);
    }
    res = (res*10)+tmp;
    num -= tmp*m;
    m /= 10;
  }

  return res;
}

int main() {
  printf("%d", maximum69Number(9999));
}