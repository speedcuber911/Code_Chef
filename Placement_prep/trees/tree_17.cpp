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

bool print_a(node * root,int key)
{
  if(root==NULL)
    return false;
  if(root->val == key)
    return true;
  if(print_a(root->left,key) || print_a(root->right,key))
  {
    cout<<root->val;
    return true;
  }
  return false;
}
int main()
{
  node *root = make(1);
  root->left        = make(2);
  root->right       = make(3);
  root->left->left  = make(4);
  root->left->right = make(5);
  root->left->right->left  = make(7);
  int key;
  cin>>key;
  print_a(root,key);
  return 0;
}
