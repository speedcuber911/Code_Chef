#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>

using namespace std;
//Utility functions/structures
typedef struct node{char val;struct node *left;struct node * right;}node;
node * make(char val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}

void _fill(vector<int>arr,int i,vector<int>&depth)
{
  if(depth[i])
    return;
  if(arr[i]==-1)
    {
      depth[i]=1;
      return;
    }
  if(depth[arr[i]]==0)
    _fill(arr,arr[i],depth);
  depth[i] = depth[arr[i]] + 1;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<int>depth(arr.size(),0);
  for(int i=0;i<arr.size();i++)
    _fill(arr,i,depth);
  int maxed = INT_MIN;
  for(int i=0;i<depth.size();i++)
    maxed = max(maxed,depth[i]);
  cout<<"The depth is "<<maxed<<endl;
  return 0;
}
