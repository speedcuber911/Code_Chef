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
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

int main()
{
  node * root = init(root);//0-6 tree
  // trav(root);
  queue<node *> qu;
  qu.push(root);
  qu.push(NULL);
  int level = 1;
  int n = 2,m=3;
  node * temp;
  vector<int>mish;
  while(!qu.empty())
  {
      temp  = qu.front();
      qu.pop();
      if(temp == NULL)
      {
        if(!qu.empty())
          qu.push(NULL);
        level++;
      }
      else
      {
        if(level >= n && level <= m)
          mish.push_back(temp->val);
        if(temp->left!=NULL)
          qu.push(temp->left);
        if(temp->right!=NULL)
          qu.push(temp->right);
      }
  }
  for(int i=0;i<mish.size();i++)
    cout<<mish[i]<<"\t";
  return 0;
}
