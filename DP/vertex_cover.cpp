#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
typedef struct node
{
  int val,vc;
  struct node * left;
  struct node * right;
}node;
struct node* newNode(int data)
{
    node* temp = new(node);
    temp->val = data;
    temp->left = temp->right = NULL;
    temp->vc = 0;
    return temp;
}
int v_c(node * root)
{
  if(root==NULL)
    return 0;
  if(root->vc!=0)
    return root->vc;
  if(root->left==NULL && root->right ==NULL)
    return 0;
  int size_incl=0,size_excl=0;
  size_incl = 1 + v_c(root->left) + v_c(root->right);
  if(root->left!=NULL)
    size_excl += (1 + v_c(root->left->left) + v_c(root->left->right));
  if(root->right!=NULL)
    size_excl += (1 + v_c(root->right->left) + v_c(root->right->right));
  root->vc =  min(size_excl,size_incl);
  return root->vc;
}
int main()
{
   node *root                = newNode(20);
   root->left                = newNode(8);
   root->left->left          = newNode(4);
   root->left->right         = newNode(12);
   root->left->right->left   = newNode(10);
   root->left->right->right  = newNode(14);
   root->right               = newNode(22);
   root->right->right        = newNode(25);
   cout<<v_c(root);
  return 0;
}
