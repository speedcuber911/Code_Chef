#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<queue>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

bool child_sum(node *root)
{
  int l=0,r=0;
  if(!root || (root->left==NULL && root->right==NULL))
    return true;
  if(root->left!=NULL)
    l = root->left->val;
  if(root->right!=NULL)
    r = root->right->val;
  if(root->val == (l+r) && child_sum(root->left) &&
      child_sum(root->right))
        return true;
  return false;
}
int main()
{
  node  *root  = make(10);
  root->left         = make(8);
  root->right        = make(2);
  root->left->left   = make(3);
  root->left->right  = make(5);
  root->right->right = make(2);
  if(child_sum(root))
    cout<<"Yes obeys\n";
  else
    cout<<"Not\n";
  return 0;
}
