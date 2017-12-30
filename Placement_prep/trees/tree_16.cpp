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

int sum_up(node * root)
{
  if(root==NULL)
    return 0;
  return (root->val + sum_up(root->left) + sum_up(root->right));
}
bool check_sum(node * root)
{
  int l_s=0,r_s=0;
  if(root==NULL)
    return true;
  if(root->left==NULL && root->right == NULL)
    return true;
  l_s = sum_up(root->left);
  r_s = sum_up(root->right);
  return (root->val == (l_s + r_s) &&
          check_sum(root->left) &&
          check_sum(root->right));
}
int main()
{
  // node * root = init(root);
  node *root  = make(26);
    root->left         = make(10);
    root->right        = make(3);
    root->left->left   = make(4);
    root->left->right  = make(6);
    root->right->right = make(3);
  if(check_sum(root))
    cout<<"Yes\n";
  // cout<<sum_up(root)<<endl;
  return 0;
}
