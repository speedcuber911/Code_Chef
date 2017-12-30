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

bool bal(node * root,int &height)
{
  if(root==NULL)
    {
      height = 0;
      return true;
    }
  int lh,rh;
  l = bal(root->left,lh);
  r = bal(root->right,rh);
  if(lh>rh)
    height = 1 + lh;
  else
    height  = 1 + rh;
  if(abs(lh-rh)>1)
    return false;
  return (l&&r);
}

int main ()
{
  node * root =  init(root);
  if(bal(root))
    cout<<"Its balanced\n";
  return 0;
}
