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

void pre_trav(node * root)
{
  if(root==NULL)
    return;
  cout<<root->val;
  pre_trav(root->left);
  pre_trav(root->right);
}
void in_trav(node * root)
{
  if(root==NULL)
    return;
  in_trav(root->left);
  cout<<root->val;
  in_trav(root->right);
}
void post_trav(node *root)
{
  if(root==NULL)
    return;
  post_trav(root->left);
  post_trav(root->right);
  cout<<root->val;
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  in_trav(root);
  cout<<"\n";
  pre_trav(root);
  cout<<"\n";
  post_trav(root);
  cout<<"\n";
  return 0;
}
