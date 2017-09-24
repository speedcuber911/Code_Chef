
#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right; struct node * nextlev;}node;
node * make(int val)
{node *root = new(node);root->val = val;root->left = NULL;root->right = NULL; root->nextlev = NULL;return root;}
node * init(node * root)
{root = make(0);root->right  = make(1);root ->left = make(2);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

int sum_up(node * root)
{
    if(root==NULL)
      return 0;
    return (root->val + (sum_up(root->left) + sum_up(root->right)));
}
bool sum_util(node * root)
{
  if(root == NULL || (root->left==NULL && root->right ==NULL))
    return true;
  if(root->val == (sum_up(root->left) + sum_up(root->right))  && sum_util(root->left) && sum_util(root->right))
    return true;

    return false;
}
bool leaf(node *root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return 1;
}
int is_sum_t(node * root)
{
  if(root==NULL || leaf(root))
    return 1;
  int l=0,r=0;
  if(is_sum_t(root->left) && is_sum_t(root->right))
  {
    if(root->left==NULL)
      l=0;
    else
        if(leaf(root->left))
          l = root->left->val;
    else
      l = 2*root->left->val;
    if(root->right==NULL)
      r=0;
    else
        if(leaf(root->right))
          r = root->left->val;
    else
          r = 2*root->left->val;
    return(root->val = (l + r));
  }
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  if(sum_util(root))
    cout<<"YES sum tree\n";
  else
      cout<<"NOT";
  return 0;
}
