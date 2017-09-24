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
{root = make(10);root->right  = make(7);root ->left = make(-2);root->left->left = make(8);root->left->right  = make(-4);/*root->right->left  = make(5);root->right->right  = make(6);*/return root;}

int max_s = INT_MIN;
int max_path_sum(node * root,int val)
{
  if(root==NULL)
    return 0;
  val += root->val;
  if(root->left==NULL && root->right==NULL)
  {
    max_s = max(val,max_s);
    return max_s;
  }
  return max(max_path_sum(root->left,val),max_path_sum(root->right,val));
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  cout<<max_path_sum(root,0);
  return 0;
}
