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

int max_sump(node * root,int &sum)
{
  if(!root)
    return 0;
  int l = max_sump(root->left,sum);
  int r = max_sump(root->right,sum);
  int max_single = max(max(l,r)+root->val,root->val);
  int max_top = max(max_single,l+r+root->val);
  sum = max(sum,max_top);
  return max_single;
}
int main()
{
   node *root = make(10);
   root->left        = make(2);
   root->right       = make(10);
   root->left->left  = make(20);
   root->left->right = make(1);
   root->right->right = make(-25);
   root->right->right->left   = make(3);
   root->right->right->right  = make(4);
   int sum = INT_MIN;
   max_sump(root,sum);
   cout<<sum<<endl;
  return 0;
}
