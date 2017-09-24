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

void double_tree(node * root)
{
  node * temp;
  if(root==NULL)
    return;
  double_tree(root->left);
  double_tree(root->right);
  temp = root->left;
  root->left = make(root->val);
  root->left->left = temp;
}
void post_trav(node *root)
{
  if(root==NULL)
    return;
  post_trav(root->left);
  post_trav(root->right);
  cout<<root->val<<" ";
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  post_trav(root);//
  cout<<endl;
  double_tree(root);
  post_trav(root);//
  return 0;
}
