#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int sum = l1->val + l2->val;
  ListNode* list = new ListNode(sum%10);
  l1 = l1->next;
  l2 = l2->next;
  ListNode* first = list;
  int overhead = 0;

  if(sum >= 10) {
    overhead = 1;
  }

  while (l1 != nullptr || l2 != nullptr || overhead != 0) {
    int sum = overhead;
    overhead = 0;
    if (l1 != nullptr) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      sum += l2->val;
      l2 = l2->next;
    }

    if (sum >= 10) {
      overhead = 1;
      sum %= 10;
    }

    list->next = new ListNode(sum);
    list = list->next;
  }
  if(first->val > 10) {
    first->val %= 10;
    return new ListNode(1, first);
  }
  return first;
}

int main() {
  ListNode* list1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* list2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  ListNode* result = addTwoNumbers(list1, list2);

  long sum = 0;
  long c = 0;
  while(result != nullptr) {
    printf("%d -> ", result->val);
    sum += result->val * (long)floor(pow(10, c++));
    result = result->next;
  }
  printf("\nsum = %d\n", sum);
  printf("expected = 807");
}