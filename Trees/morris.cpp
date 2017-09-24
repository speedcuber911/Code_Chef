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

void morris(node * root)
{
  node * cur, * prev;
  cur =  root;
  while(cur!=NULL)
  {
    if(cur->left==NULL)
      {
        cout<<cur->val;
        cur = cur->right;
      }
    else
    {
      prev = cur->left;
      while(prev->right!=NULL && prev->right!=cur)
        prev = prev->right;
      if(prev->right==NULL)
      {
        prev->right = cur;
        cur = cur->left;
      }
      else
      {
        prev->right = NULL;
        cout<<cur->val;
        cur = cur->right;
      }
    }
  }
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  morris(root);
  cout<<endl;
  return 0;



}
