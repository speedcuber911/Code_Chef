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

bool identical(node *root1,node *root2)
{
  // if( (root1==NULL && root2!=NULL) || (root2!=NULL && root1==NULL) )
    // return false;
  if(root1==NULL && root2==NULL)
    return true;
  if(root1==NULL || root2==NULL)
    return false;
  return( (root1->val == root2->val) &&
            identical(root1->left,root2->left) &&
            identical(root1->right,root2->right) );
}
bool subtree(node *root,node *root2)
{
  if(root==NULL)
    return false;
  if(root2==NULL)
    return true;
  if(identical(root,root2))
    return true;
  return(subtree(root->left,root2) ||subtree(root->right,root2));
}
int main()
{
  node *root = init(root);
  node * root2 = make(1);root2->left = make(3);root2->right = make(4);subtree(root,root2);
  if(subtree(root,root2))
    cout<<"YAss\n";
  return 0;
}
