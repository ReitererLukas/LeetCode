#include <stdio.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
  if (root == nullptr)
    return root;
  TreeNode *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  root->left = invertTree(root->left);
  root->right = invertTree(root->right);
  return root;
}

void printTree2D(TreeNode *node)
{
  if (node == nullptr)
    return;
  printTree2D(node->left);
  printf("%d ", node->val);
  printTree2D(node->right);
}

TreeNode *createTree()
{
  TreeNode *root = new TreeNode(4);
  TreeNode *tmp1 = new TreeNode(2);
  root->left = tmp1;
  TreeNode *tmp2 = new TreeNode(1);
  tmp1->left = tmp2;
  tmp2 = new TreeNode(3);
  tmp1->right = tmp2;
  tmp1 = new TreeNode(6);
  root->right = tmp1;
  tmp2 = new TreeNode(5);
  tmp1->left = tmp2;
  tmp2 = new TreeNode(7);
  tmp1->right = tmp2;
  return root;
}

int main()
{
  TreeNode *root = createTree();
  printTree2D(root);
  printf("\n");
  invertTree(root);
  printTree2D(root);
  printf("\n");
}
