#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string countAndSay(int n)
{
  if (n == 1)
    return "1";
  else
  {
    //printf("Hi%d",n);
    string oldStr = countAndSay(n - 1), newStr = "";
    int i = 0;
    while (i < oldStr.size())
    {
      int counter = 1;
      while (i + counter < oldStr.size() && oldStr.at(i) == oldStr.at(i + counter))
        counter++;
      newStr.append(to_string(counter)).push_back(oldStr.at(i));
      i += counter;
    }
    return newStr;
  }
}

int main()
{
  cout << countAndSay(5) << endl;
}