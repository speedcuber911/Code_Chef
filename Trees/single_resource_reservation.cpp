#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

typedef struct node{
  struct node * left;
  struct node * right;
  int time;
}node;

node *newNode(int item)
{
    node *temp = new(node);
    temp->time = item;
    temp->left = temp->right = NULL;
    return temp;
}
node * insert(node * root,int val,int k)
{
  if(root==NULL)
    return newNode(val);
  if( (val-k) < root->time && (val+k) > root->time)
    return root;
  if(val > root->time)
    root->right = insert(root->right,val,k);
  else
    root->left = inset(root->left,val,k);
  return root;  
}
int main()
{
  return 0;
}
