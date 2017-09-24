#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right; struct node * next;}node;
node * make(int val)
{node *root = new(node);root->val = val;root->left = NULL;root->next=NULL;root->right = NULL;return root; }
node * init(node * root)
{root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

void pop_next(node * root)
{
  struct node * aux = NULL;
  if(root==NULL)
    return
  pop_next(root->right);
  p->next = aux;
  aux = p;
  pop_next(root->left);
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  pop_next(root);
  return 0;
}
