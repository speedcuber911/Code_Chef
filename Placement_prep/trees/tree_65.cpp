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

int left_l_sum(node * root,bool marker)
{
  if(!root)
    return 0;
  if(root->left==NULL && root->right==NULL)
      {
        if(marker)
            return root->val;          
        if(!marker)
          return 0;
      }
  return (left_l_sum(root->left,true)+left_l_sum(root->right,false));
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  trav(root);
  cout<<endl;
  cout<<left_l_sum(root,false)<<endl;
}
