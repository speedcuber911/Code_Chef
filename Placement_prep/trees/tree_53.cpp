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
  queue<pair<node *,int> >qu;
  map<int ,node*>dict;
  int hd = 0;
  qu.push(make_pair(root,hd));
  dict[0] = root;
  while(!qu.empty())
  {
      pair<node*,int> temp = qu.front();
      qu.pop();
      // cout<<temp.first->val<<"\t";
      if(dict.find(temp.second) == dict.end())
          dict[temp.second] = temp.first;      
      if(temp.first->left!=NULL)
          qu.push(make_pair(temp.first->left,temp.second-1));
      if(temp.first->right!=NULL)
        qu.push(make_pair(temp.first->right,temp.second+1));
  }
  for(auto it = dict.begin();it!=dict.end();++it)
  {
    cout<<it->second->val<<"\t";
  }
  return 0;
}
