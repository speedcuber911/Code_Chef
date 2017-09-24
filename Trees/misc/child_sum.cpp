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

bool check_child_sum(node * root)
{
  if(root==NULL)
    return 1;
  if(root->left==NULL && root->right==NULL)
    return 1;
  if(root->val == (root->left->val)+(root->right->val))
    return 1;
  else
      return 0;
  return (check_child_sum(root->left) && check_child_sum(root->right));
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  if(check_child_sum(root))
    cout<<"Exists\n";
  else
    cout<<"No\n";
  return 0;
}
