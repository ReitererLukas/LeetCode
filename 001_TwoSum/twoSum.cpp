#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<int> sol_brutForce(vector<int>& nums, int target)
{
  for(int i = 0;i<nums.size()-1;i++)
  {
    for(int j = i+1;j<nums.size();j++)
    {
      if(nums[i] + nums[j] == target)
        return {i,j};
    }
  }

  return {};
}

//HashMap funktioniert in C++ nicht

int main()
{
  vector<int> nums = {1,2,3,4,5,6};
  int target = 9;
  vector<int> res;

  res = sol_brutForce(nums, target);
  printf("%d | %d",res[0],res[1]);

  return 0;
}