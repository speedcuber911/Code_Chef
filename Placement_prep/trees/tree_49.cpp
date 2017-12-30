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
typedef struct node{char val;struct node *left;struct node * right;}node;
node * make(char val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

void pathlen(node *root,vector<int>&arr,vector<bool>&vis,int index,int k)
{
  if(!root)
    return ;
  arr[index] = root->val;
  vis[index] = false;
  index++;
  if(root->left==NULL && root->right==NULL)
    if(index-k-1 >=0 && vis[index-k-1]==false)
      {
        cout<<arr[index-k-1]<<"\t";
        vis[index-k-1] = true;
        return;
      }
  pathlen(root->left,arr,vis,index,k);
  pathlen(root->right,arr,vis,index,k);

}

int main()
{
  node *  root = make(1);
    root->left = make(2);
    root->right = make(3);
    root->left->left = make(4);
    root->left->right = make(5);
    root->right->left = make(6);
    root->right->right = make(7);
    root->right->left->right = make(8);
  int k;
  cin>>k;
  vector<int>arr(100);
  vector<bool>vis(100,false);
  pathlen(root,arr,vis,0,k);
  return 0;
}
