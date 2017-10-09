#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

typedef struct t_node
{
  int val;
  struct t_node * right;
  struct t_node *left;
}t_node;

int count_nodes(t_node * root)
{
  if(root==NULL)
    return 0;
  return (1+count_nodes(root->left)+count_nodes(root->right));
}
bool is_comp(t_node *root,int count,int indice)
{
  if(root==NULL)
    return true;
  if(indice >= count)
    return false;
  if ( is_comp(root->left,count,2*indice+1) && is_comp(root->right,count,2*(indice+1)) )
    return true;
}
bool is_heap(t_node * root)
{
  if(root->left == NULL && root->right == NULL)
    return true;
  if(root->right == NULL)
    return(root->val >= root->left->val);
  else
  {
    if((root->val >= root->left->val) && (root->val >= root->right->val))
      return (is_heap(root->left) && is_heap(root->right));
    return false;
  }
}
t_node * newNode(int v)
{
  t_node * temp = new(t_node);
  temp->left = temp->right = NULL;
  temp->val = v;
  return temp;
}
int main()
{
    t_node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
  int count = count_nodes(root);
  if(is_comp(root,count,0) && is_heap(root))
    cout<<"Yes\n";
  else
      cout<<"No\n";
  return 0;
}
