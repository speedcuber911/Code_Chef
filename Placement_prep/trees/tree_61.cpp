#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>

using namespace std;
//Utility functions/structures
typedef struct node{char val;struct node *left;struct node * right;}node;
node * make(char val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}

int max_(int a,int b)
{
  if(a>b)
    return a;
  return b;
}
int max_util(node * root,int &res)
{
  if(!root)
    return 0;
  int l = max_util(root->left,res);
  int r = max_util(root->right,res);
  int max_single = max_(root->val,max(l, r) + root->val);
  int max_top = max(max_single,(l+r+root->val));//path sum total including root
  res = max(max_top,res);
  return max_single;
}
int  main()
{
  node *root = make(10);
    root->left        = make(2);
    root->right       = make(10);
    root->left->left  = make(20);
    root->left->right = make(1);
    root->right->right = make(-25);
    root->right->right->left   = make(3);
    root->right->right->right  = make(4);
    int res = INT_MIN;
    max_util(root,res);
    cout<<res<<endl;
  return 0;
}
