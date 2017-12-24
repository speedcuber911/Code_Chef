#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right; struct node * dp;}node;
node * make(int val)
{node *root = new(node);root->val = val;root->left = NULL;root->right = NULL; return root;}
node * init(node * root)
{root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}


int maxi(node * root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->val;
  int maxed = root->val + max(maxi(root->left), maxi(root->right));
  return maxed;
}

int max_bet_two_leaves(node * root,int & maxed)
{
  if(!root)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return 0;
  maxed =  max( maxed,(root->val + maxi(root->left) + maxi(root->right)));
  return max(max_bet_two_leaves(root->left,maxed),max_bet_two_leaves(root->right,maxed));
}
int process(node * root,int & maxed)
{
  if(!root)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->val;
  int left_ = process(root->left,maxed);
  int right_ = process(root->right,maxed);
  if(root->left!=NULL && root->right!=NULL)
      maxed = max(maxed, left_ + right_ + root->val);
  return max(right_+root->val,left_+root->val);
}
int main()
{
  // node * root = init(root);
  node *root = make(-15);
  root->left = make(5);
  root->right = make(6);
  root->left->left = make(-8);
  root->left->right = make(1);
  root->left->left->left = make(2);
  root->left->left->right = make(6);
  root->right->left = make(3);
  root->right->right = make(9);
  root->right->right->right= make(0);
  root->right->right->right->left= make(4);
  root->right->right->right->right= make(-1);
  root->right->right->right->right->left= make(10);
  int maxed = INT_MIN;
  // max_bet_two_leaves(root, maxed);
  process(root,maxed);
  cout<<maxed<<endl;
  return 0;
}
