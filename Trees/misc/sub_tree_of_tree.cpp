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

bool identical(node *root, node *root2)
{
  if(root==NULL && root2==NULL)
    return true;
  if(root==NULL || root2==NULL)
    return false;
  return (root->val == root2->val &&
    identical(root->left,root2->left) &&
    identical(root->right,root2->right)
    );
}

bool is_sub(node *root,node * root2)
{
  if(root2==NULL)
    return 1;
  if(root==NULL)
    return 0;
  if(identical(root,root2))
    return 1;
  return(is_sub(root->left,root2) || is_sub(root->right,root2));
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  node * root2 = init(root2);//makes  a 0-6 tree
  if(is_sub(root,root2))
    cout<<"YES\n";
  return 0;
}
