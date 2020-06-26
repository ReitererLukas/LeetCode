#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool doesItCloes(char c)
{
  if (c == ')' || c == ']' || c == '}')
    return true;
  return false;
}

char getOpposite(char c)
{
  switch (c)
  {
  case '(':
    return ')';
  case '{':
    return '}';
  case '[':
    return ']';
  }
  return 'e';
}

bool sol_1(string s)
{
  vector<char> v;

  for (auto i = s.begin(); i < s.end(); i++)
  {
    printf("%c", *i);
    if (doesItCloes(*i))
    {
      if (v.size() == 0)
        return false;
      else if (v.back() != *i)
        return false;
      else
        v.pop_back();
    }
    else
    {
      v.push_back(getOpposite(*i));
    }
  }

  if (v.size() == 0)
    return true;
  else
    return false;
}

int main()
{
  string s = "]";
  printf("\nIs valid: %s", sol_1(s) ? "true" : "false");
}