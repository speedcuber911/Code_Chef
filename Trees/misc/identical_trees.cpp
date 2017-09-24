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

bool  ident(node *a, node * b)
{
  if(a==NULL && b==NULL)
    return 1;
  if(a!=NULL && b!=NULL)
    {
      if((a->val==b->val) && ident(a->right,b->right) && ident(a->left,b->left))
        return 1;
    }
  else
    return 0;
}

void in_trav(node * root)
{
  if(root==NULL)
    return;
  in_trav(root->left);
  cout<<root->val;
  in_trav(root->right);
}

int main()
{
  node * root = init(root);//makes  a 0-6 tree
  node * root2 = init(root2);
  // in_trav(root);
  // cout<<endl;
  // in_trav(root2);
  if(ident(root,root2))
    cout<<"yes\n";
  else
    cout<<"no\n";
  return 0;
}
