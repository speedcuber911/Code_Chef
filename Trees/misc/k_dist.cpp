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

void kdist(node * root,int k)
{
  if(root==NULL)
    return;
  if(k==0)
    cout<<root->val<<" ";
  kdist(root->left,k-1);
  kdist(root->right,k-1);
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  int k ;
  cin>>k;
  kdist(root,k);
  return 0;
}
