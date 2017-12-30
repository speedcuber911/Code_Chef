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

void min_max(node * root,int &maxy,int &miny)
{
  if(!root)
    return;
  maxy = max(root->val,maxy);
  miny = min(root->val,miny);
  min_max(root->left,maxy,miny);
  min_max(root->right,maxy,miny);
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  int miny=INT_MAX,maxy=INT_MIN;
  min_max(root,maxy,miny);
  cout<<"maximum is "<<maxy<<" minimum is "<<miny<<endl;
  return 0;
}
