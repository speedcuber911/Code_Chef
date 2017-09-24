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

int height(node *root)
{
  if(root==NULL)
    return 0;
  else
    return max(height(root->left)+1 ,height(root->right)+1);
}
void max_width(node * root,int count[],int level)
{
  if(root==NULL)
    return;
  count[level]++;
  max_width(root->left,count,level+1);
  max_width(root->right,count,level+1);
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  int count[height(root)];
  for(int i=0;i<height(root);i++)count[i]=0;//set zeroes
  max_width(root,count,0);// Do level order traversal and find level with maximum no. of nodes in i
  int result = 0;
  for(int i=0;i<height(root);i++)
  result = max(count[i],result);
    // cout<<count[i]<<" ";
  cout<<result;
  return 0;
}
