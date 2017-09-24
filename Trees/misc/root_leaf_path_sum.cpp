#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val)
{node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
node * init(node * root)
{root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

bool pres_sum(node * root, int sum)
{
  if(root==NULL)
    return 0;
  if(sum==0 && root->left==NULL && root->right==NULL)
    return 1;
  if(sum<0)
    return 0;
  return (pres_sum(root->left,sum-root->val) || pres_sum(root->right,sum-root->val));
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  if(pres_sum(root,4))
    cout<<"yes\n";
  else
    cout<<"no\n";
  return 0;
}
