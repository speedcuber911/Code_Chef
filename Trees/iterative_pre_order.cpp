#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val)
{node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
node * init(node * root)
{root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

void iterative_pre_order(node * root)
{
    if(root==NULL)
      return;
    stack<node * >s;
    s.push(root);
    while(!s.empty())
    {
      node * temp = s.top();
      cout<<temp->val;
      s.pop();
      if(temp->right!=NULL)
        s.push(temp->right);
      if(temp->left!=NULL)
        s.push(temp->left);
    }
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  iterative_pre_order(root);
  return 0;
}
