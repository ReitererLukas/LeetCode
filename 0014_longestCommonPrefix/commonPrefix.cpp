#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string sol_verticalSearch(vector<string> &strs)
{
  string common = "";
  if (strs.size() == 0)
    return "";
  else
  {
    common = strs.back();
    strs.pop_back();
    for (string s : strs)
    {
      int minLength = min(common.size(), s.size());
      //printf("common = %s | s = %s | MinLength: %d\n",common, s, minLength);
      if (minLength > 0)
      {
        string newCommon = "";
        for (int i = 0; i < minLength; i++)
        {
          if (common.at(i) == s.at(i))
          {
            newCommon.push_back(common.at(i));
          }
          else
            break;
        }
        common = newCommon;
      }
      else
        return "";
    }
    return common;
  }
}

int main()
{
  vector<string> v;
  v.push_back("");
  v.push_back("b");
  string s = sol_verticalSearch(v);
  printf("Output: %s\n",s.c_str());
}