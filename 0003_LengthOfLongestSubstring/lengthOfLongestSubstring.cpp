#include <stdio.h>
#include "string"
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
/* first version
int lengthOfLongestSubstring(string s) {
  int res = 0;
  deque<int> q;

  for (int i = 0;i<s.length(); i++) {
    bool substrinContains = false;
    for(int j = 0; j<q.size();j++) {
      if (s.at(i) == q.at(j)) {
        substrinContains = true;
        break;
      }
    }
    if (!substrinContains) {
      q.push_back(s.at(i));
      res = max(res, (int)q.size());
    } else {
      char sub;
      do {
        sub = q.front();
        printf("%c\n",sub);
        q.pop_front();
      } while(sub != s.at(i));
      q.push_back(s.at(i));
    }
  }
  return res;
}
 */


// every ascii sign is possible --> 256 signs --> 256 elements in array
// in the vector we save the last position of the element (char is casted to int and directly referenced)
int lengthOfLongestSubstring(string s) {
  int res = 0;
  int lastSub = 0;
  // creates array with 256 elements all set to -1
  vector<int> v(256,-1);
  
  for (int i = 0;i<s.size();i++) {
    lastSub = max(lastSub, v[s[i]]+1); // get the highest last double char
    res = max(res, i-lastSub+1); // get highest score
    v[s[i]] = i; // update last position of the char
  }

  return res;
}

int main() {
  printf("%d\n",lengthOfLongestSubstring("abcjakdef"));
}