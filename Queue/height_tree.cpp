#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<queue>

using namespace std;

typedef struct node{
  int val;
  struct node*right;
  struct node *left;
}tree;

tree* newNode(int data)
{
 tree *node = new(tree);
 node->val = data;
 node->left = NULL;
 node->right = NULL;

 return(node);
}

int height(tree *root)
{
  if(root ==NULL)
    return 1;
  int level = 1;
  queue<tree *>q;
  q.push(root);
  while(!q.empty())
  {
      tree *x = q.front();
      q.pop();
      if(x->left!=NULL)
      {
        q.push(x->left);
      }
      if(x->right!=NULL)
      {
        q.push(x->right);
      }
      // if(x->left==NULL && x->right==NULL)
      //   return level;
      if(x->left!=NULL || x->right!=NULL)
          level++;
  }
  return level;
}
int main()
{
  tree *root         = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);
  cout<<height(root);
  return 0;
}
