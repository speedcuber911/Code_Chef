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
bool is_complete_bt(tree *root)
{
  if(root==NULL)
    return true;
  bool t = false;
  queue<tree*>q;
  q.push(root);
  while(!q.empty())
  {
    tree *temp = q.front();
    q.pop=();
    if(temp->left!=NULL)
    {
      if(t == true)
        return false;
      q.push(temp->left);
    }
    else
      t = true;
    if(temp->right!=NULL)
    {
      if(t == true)
        return false;
      q.push(temp->right);
    }
    else
      t = true;
  }
  return true;
}
int main()
{
tree *root  = newNode(1);
root->left         = newNode(2);
root->right        = newNode(3);
root->left->left   = newNode(4);
root->left->right  = newNode(5);
root->right->right = newNode(6);
if(is_complete_bt(root))
  cout<<"Yeah, complete ";
else
    cout<<"Incomplete";

}
