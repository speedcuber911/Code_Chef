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
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}

node * remove_nodes(node * root,int level,int k)
{
  if (root == NULL)
  		return NULL;
  	root->left = remove_nodes(root->left, level + 1, k);
  	root->right = remove_nodes(root->right, level + 1, k);
  	if (root->left == NULL && root->right == NULL && level < k)
  	{
  		delete root;
  		return NULL;
  	}
  	return root;
  }
int main()
{
  

  node *root = make(1);
   root->left = make(2);
   root->right = make(3);
   root->left->left = make(4);
   root->left->right = make(5);
   root->left->left->left = make(7);
   root->right->right = make(6);
   root->right->right->left = make(8);
  trav(root);
  cout<<endl;
  trav(remove_nodes(root,1,4));
  return 0;
}
