#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int maxArea(vector<int> &height)
{
  int maxArea = 0;
  for (int i = 0; i < height.size(); i++)
  {
    if (height[i] == 0 || (height.size() - i) * height[i] < maxArea)
      continue;
    int add = ceil(maxArea / (double)height[i]);
    for (int j = height.size() - 1; j >= i + add; j--)
    {
      int h = min(height[i], height[j]);
      maxArea = max(maxArea, (j - i) * h);
    }
  }
  return maxArea;
}

int main()
{
  vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  //   vector<int> v = {1, 2, 4, 3};
  printf("%d", maxArea(v));
}