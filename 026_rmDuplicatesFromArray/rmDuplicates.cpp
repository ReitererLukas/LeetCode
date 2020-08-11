#include <stdio.h>
#include <vector>

using namespace std;

void shiftArray(vector<int> &nums, int pos)
{
  int tmp = nums[pos];
  for (int i = pos; i < nums.size() - 1; i++)
    nums[i] = nums[i + 1];
  nums[nums.size() - 1] = tmp;
}

int removeDuplicates1(vector<int> &nums)
{
  int i = 1;
  int length = nums.size();
  while (i < length)
  {
    if (nums[i] < nums[i - 1])
      return i;
    if (nums[i] == nums[i - 1])
    {
      shiftArray(nums, i);
      length--;
    }
    else
      i++;
  }
  return length;
}

int removeDuplicates2(vector<int> &nums)
{
  vector<int> diffNums;

  diffNums.push_back(nums[0]);
  for (int i = 1; i < nums.size(); i++)
  {
    if(nums[i] > nums[i-1])
      diffNums.push_back(nums[i]);
  }

  for(int i = 0;i<diffNums.size();i++)
  {
    nums[i] = diffNums[i];
  }
  return diffNums.size();
}

int main()
{
  vector<int> nums;
  //nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  //nums = {1, 1};
  //nums = {1, 1};
  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int l = removeDuplicates2(nums);
  for (int i = 0; i < l; i++)
  {
    printf("%d", nums[i]);
    if (i + 1 != l)
      printf(", ");
    else
      printf("\n");
  }
}