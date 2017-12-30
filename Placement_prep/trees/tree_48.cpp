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
typedef struct node{char val;struct node *left;struct node * right;}node;
node * make(char val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

bool red_black(node * root,int &minh ,int &maxh)
{
  if(!root)
  {
    maxh = minh = 0;
    return true;
  }
  int lxmh,lmnh;
  int rxmh,rmnh;
  if(!red_black(root->left,lxmh,lmnh))
    return false;
  if(!red_black(root->right,rxmh,rmnh))
    return false;
  maxh = max(lxmh,rxmh)+ 1;
  minh = min(lmnh,rmnh) +1;
  if(maxh <= 2*minh)
    return true;
  return false;
}

int main()
{
  node * root = make(10);
    root->left = make(5);
    root->right = make(100);
    root->right->left = make(50);
    root->right->right = make(150);
    root->right->left->left = make(40);
    int minh,maxh;
    red_black(root,minh,maxh);
  return 0;
}
