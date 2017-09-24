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

bool is_mirror(node * root1, node * root2)
{
  if(root1==NULL && root2==NULL)
    return true;
  if(root1==NULL || root2==NULL)
    return false;
  return is_mirror(root1->left,root2->right) && is_mirror(root1->right,root2->left);
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  if(root==NULL)
    cout<<"YES\n";
  else
    if(is_mirror(root->left,root->right))
      cout<<"YES\n";
  else
      cout<<"NO";
  return 0;
}
