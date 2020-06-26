#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int translate(char c)
{
  /*  Symbol        Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000*/
  switch (c)
  {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
  return -1;
}

int sol_1(string s)
{
  int res = 0;
  int last = translate(s.at(0));
  for (int i = 1; i < s.size(); i++)
  {
    int curr = translate(s.at(i));
    if (curr <= last)
    {
      res += last;
      last = curr;
    }
    else
    {
      last = curr - last;
    }
  }
  return res + last;
}

int main()
{
  string s = "MCMXCIV"; //1994
  printf("%d\n", sol_1(s));
  return 0;
}

/*
Wenn der Vorgänger kleiner ist muss man den Vorgänger vom derzeitigen subtrahieren
Nur wenn der Nachgänger größer ist, darf ich den Wert addieren
*/