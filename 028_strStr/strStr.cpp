#include <stdio.h>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
  if (haystack.size() == 0 && needle.size() == 0)
    return 0;
  if (haystack.size() == 0)
    return -1;
  if (needle.size() == 0)
    return 0;
  if (needle.size() > haystack.size())
    return -1;
  for (int i = 0; i <= haystack.size() - needle.size(); i++)
  {
    if (haystack.at(i) == needle.front())
    {
      int isWorking = 1;
      for (int j = 1; j < needle.size(); j++)
      {
        if (haystack.at(i + j) != needle.at(j))
          isWorking = 0;
      }
      if (isWorking == 1)
        return i;
    }
  }
  return -1;
}

int main()
{
  string haystack = "hello", needle = "ll";
  printf("%d\n", strStr(haystack, needle));
}