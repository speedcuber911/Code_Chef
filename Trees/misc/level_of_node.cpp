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

int level(node * root, int data,int lev)
{
  if(root==NULL)
    return 0;
  if(root->val == data)
      return lev;
  int g = level(root->left,data,lev+1);
  return (g==0)?level(root->right,data,lev+1):g;
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  int data;
  cin>>data;
  cout<<level(root,data,1);
  return 0;
}
