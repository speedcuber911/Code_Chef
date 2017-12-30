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
node * init2(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(7);return root;}

bool is_eq(node * root1,node * root2)
{
  if(root1== NULL && root2==NULL)
    return true;
  if(root1->val == root2->val && is_eq(root1->left,root2->left)
     &&  is_eq(root1->right,root2->right))
        return true;
  return false;
}
int main()
{
  node * root = init (root);
  node * root2 = init2(root2);
  if(is_eq(root,root2))
    cout<<"Identical\n";
  else
      cout<<"Not not\n";
  return 0;
}
