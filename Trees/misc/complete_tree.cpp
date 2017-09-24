#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>

using namespace std;
//Utility functions/structures
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val)
{node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
node * init(node * root)
{root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

bool is_complete(node * root)
{
  if(root==NULL)
    return 1;
  queue<node *>q;
  q.push(root);
  bool flip =0;
  while(!q.empty())
  {
    node * temp = q.top();
    q.pop();
    if(temp->left!=NULL)
    {
      q.push(temp->left);
      if(flip)
        return false;
    }
    else
      flip=1;
    if(temp->right!=NULL)
    {
      q.push(temp->right);
      if(flip)
        return false;
    }
    else
      flip = 1;
  }
  return true;
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  return 0;
}
