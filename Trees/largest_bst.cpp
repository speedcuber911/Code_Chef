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

int largest_bst(node *root,int & maxi)
{
  if(!root)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->val;
  int l = largest_bst(root->left);
  int r = largest_bst(root->right);
  if(root->val > l && root->val < r)
    maxi = max(maxi,3);


}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  return 0;
}
