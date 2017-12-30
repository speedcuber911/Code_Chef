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
typedef struct node{int val;struct node *left;struct node * right; node * next_right;}node;
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->next_right=NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

int main()
{
  node * root = init(root);
  queue<node * >qu;
  qu.push(root);
  qu.push(NULL);
  node * temp;
  while(!qu.empty())
  {
    temp = qu.front();
    qu.pop();
    if(temp==NULL)
      {
        if(qu.empty())
          qu.push(NULL);
      }
    else
    {
      temp->next_right = qu.front();
      if(temp->left)
        qu.push(temp->left);
      if(temp->right)
        qu.push(temp->right);
    }
  }

  return 0;
}
