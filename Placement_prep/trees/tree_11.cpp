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

void paths(node * root,vector< vector<int> >&liste,vector<int>temp)
{
  if(root==NULL)
    return ;
  temp.push_back(root->val);
  if(root->left==NULL && root->right==NULL)
  {
    liste.push_back(temp);
    return;
  }
  paths(root->left,liste,temp);
  paths(root->right,liste,temp);
}
int main()
{
  node * root = init(root);
  vector<vector<int> >liste;
  vector<int> temp;
  paths(root,liste,temp);
  for(int i=0;i<liste.size();i++)
    {
      for(int j=0;j<liste[i].size();j++)
        cout<<liste[i][j]<<"\t";
      cout<<endl;
    }
}
