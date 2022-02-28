#include <stdio.h>
#include "vector"

using namespace std;

int removeElement(vector<int> &nums, int val)
{
  int found = 0, i = 0;
  while (i < nums.size() - found)
  {
    if (nums[i] == val)
    {
      int tmp = nums[nums.size() - found - 1];
      nums[nums.size() - found - 1] = nums[i];
      nums[i] = tmp;
      found++;
      continue;
    }
    i++;
  }
  return nums.size()-found;
}

int main()
{
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;

  int l = removeElement(nums, val);
  printf("%d\n",l);
  for (int i = 0; i < l; i++)
  {
    printf("%d, ", nums[i]);
  }
}