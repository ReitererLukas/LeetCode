#include <stdio.h>

using namespace std;

struct Node
{
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int val) : val(val), next(nullptr) {}
  Node(int val, Node *next) : val(val), next(next) {}
};

Node* addLast(Node *node, int data)
{
  Node* newNode = new Node(data);
  Node* startNode = node;
  if (node == nullptr)
    return newNode;
  else
  {
    while (node->next != nullptr)
    {
      node = node->next;
    }
    node->next = new Node(data);
  }
  return startNode;
}

Node *addFirst(Node *node, int data)
{
  return new Node(data, node);
}

int size(Node *node)
{
  if (node == nullptr)
    return 0;

  int count = 1;
  while (node->next != nullptr)
  {
    count++;
    node = node->next;
  }
  return count;
}

int getValue(Node *node, int index)
{
  if (index < 0 || index >= size(node))
    return -1;
  for (int i = 0; i < index; i++)
  {
    node = node->next;
  }
  return node->val;
}

void deleteLast(Node *node)
{
  if (node == nullptr)
    return;
  else if (node->next == nullptr)
  {
    node = nullptr;
    return;
  }

  while (node->next->next != nullptr)
  {
    node = node->next;
  }
  node->next = nullptr;
}

Node *deleteFirst(Node *node)
{
  if (node == nullptr || node->next == nullptr)
    return nullptr;
  else
  {
    Node *newStart = node->next;
    node->next = nullptr;
    return newStart;
  }
}

Node *deleteByValue(Node *node, int value)
{
  Node* startNode = node;
  if (node == nullptr)
    return nullptr;
  if (node->val == value)
    return node->next;

  Node *preNode = node;
  node = node->next;
  while (node != nullptr)
  {
    if (node->val == value)
    {
      preNode->next = node->next;
      break;
    }
    preNode = node;
    node = node->next;
  }
  return startNode;
}

void printList(Node *node)
{
  while (node != nullptr)
  {
    printf("%d ", node->val);
    node = node->next;
  }
  printf("\n");
}

int main()
{
  Node *n1 = new Node(1);
  n1 = addLast(n1, 6);
  n1 = addFirst(n1, -9);
  printf("Size: %d\n", size(n1));
  printList(n1);
  n1 = deleteFirst(n1);
  printList(n1);
  deleteLast(n1);
  printList(n1);
  n1 = deleteFirst(n1);
  for (int i = 0; i < 10; i++)
  {
    n1 = addLast(n1, i + 1);
  }
  printList(n1);
  n1 = deleteByValue(n1,5);
  n1 = deleteByValue(n1,7);
  printList(n1);
}