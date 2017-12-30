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
typedef struct node{int val;struct node *left;struct node * right; node * next;}node;
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->next=NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}
vo

void populatey(node * root,node *nexty)
{  
  if(root==NULL)
    return ;
  populatey(root->right,nexty);
  root->next = nexty;
  nexty = root;
  populatey(root->left,nexty);
}
int main()
{
  node * root = init(root);
  node * nexty = NULL;
  populatey(root,nexty);
  return 0;
}
