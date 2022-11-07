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

int getSize(ListNode *list)
{
  int count = 0;

  while (list != nullptr)
  {
    count++;
    list = list->next;
  }
  return count;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  ListNode *newList = new ListNode();
  ListNode *actualNode = newList;
  int size = getSize(l1) + getSize(l2);
  for (int i = 0; i < size; i++)
  {
    if(l1 == nullptr)
    {
      actualNode->next = l2;
      break;
    }
    else if(l2 == nullptr)
    {
      actualNode->next = l1;
      break;
    }
    else if (l1->val < l2->val)
    {
      actualNode->next = l1;
      l1 = l1->next;
    }
    else
    {
      actualNode->next = l2;
      l2 = l2->next;
    }
    actualNode = actualNode->next;
  }
  actualNode = newList->next;
  newList = nullptr;
  return actualNode;
}

void printList(ListNode *list)
{
  while (list != nullptr)
  {
    printf("%d", list->val);
    if (list->next != nullptr)
    {
      printf(",");
    }
    printf(" ");
    list = list->next;
  }
  printf("\n");
}

int main()
{
  ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode(6))));
  ListNode *l2 = new ListNode(1, new ListNode(2, new ListNode(3)));
  printList(mergeTwoLists(l1, l2));
}