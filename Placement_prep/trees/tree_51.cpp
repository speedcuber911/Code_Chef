#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<queue>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

void diagonal(node * root,int vd,map<int,int>&d_sum)
{
  if(root==NULL)
    return;
  d_sum[vd] += root->val;
  diagonal(root->left,vd+1,d_sum);
  diagonal(root->right,vd,d_sum);
}
int main()
{
  node* root = make(1);
     root->left = make(2);
     root->right = make(3);
     root->left->left = make(9);
     root->left->right = make(6);
     root->right->left = make(4);
     root->right->right = make(5);
     root->right->left->right = make(7);
     root->right->left->left = make(12);
     root->left->right->left = make(11);
     root->left->left->right = make(10);
  map<int,int>d_sum;
  diagonal(root,0,d_sum);
  for(auto it = d_sum.begin();it!=d_sum.end();++it)
    cout<<it->second<<"\n";
  return 0;
}
