#include <stdio.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
  ListNode* n1 = new ListNode(1);
  for(int i = 2;i<=10;i++)
  {
    n1 = new ListNode(i,n1);
  }
  printf("%d\n",n1->val);
}