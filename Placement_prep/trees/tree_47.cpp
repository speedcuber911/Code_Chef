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

void not_sibling(node * root)
{
  if(!root)
    return;
  if(root->left!=NULL && root->right!=NULL)
  {
    not_sibling(root->left);
    not_sibling(root->right);
  }
  else
    if(root->left!=NULL)
      {
        cout<<root->left->val<<"\n";
        not_sibling(root->left);
      }
  else
    if(root->right!=NULL)
      {
        cout<<root->right->val<<"\n";
        not_sibling(root->right);
      }
}
int main()
{
  node *root = make(1);
    root->left = make(2);
    root->right = make(3);
    root->left->right = make(4);
    root->right->left = make(5);
    root->right->left->left = make(6);
  // trav(root);
  not_sibling(root);
  return 0;
}
