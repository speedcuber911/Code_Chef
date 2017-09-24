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

void morris(node * root)
{
  if(root==NULL)
    return;
  while(root!=NULL)
  {
    if(root->left==NULL)
      {
        cout<<root->val;
        root = root->right;
      }
    else
    {
      node * cur = root->left;
      while(cur->right!=NULL and cur->right!=root)
              cur = cur->right;
      if(cur->right==root)
      {
        cur->right = NULL;
        root = root->right;
      }
      else
      {
        cout<<root->val;
        cur->right = root;
        root = root->left;
      }
    }
  }
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  morris(root);
  return 0;
}
