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

int deep_left(node * root,bool flag,int depth,int max_d)
{
  if(root==NULL)
    return 0;
  if(flag && root->left!=NULL && root->right!=NULL)
  {
    max_d = max(root->val,max_d);
    return max_d;
  }
  return max(deep_left(root->left,true,depth+1,max_d),deep_left(root->right,false,depth+1,max_d));
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  cout<<deep_left(root,0,0,0)<<endl;
  return 0;
}
