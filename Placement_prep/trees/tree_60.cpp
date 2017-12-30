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

void leaf_l(node * root,int l,int &ans)
{
  if(!root)
    return ;
  if(root->left==NULL && root->right == NULL)
      ans = min(ans,l);
  leaf_l(root->left,l+1,ans);
  leaf_l(root->right,l+1,ans);
}
int main()
{
  node *root        = make(1);
    root->left        = make(2);
    root->right       = make(3);
    root->left->left  = make(4);
    root->left->right = make(5);
  int ans= INT_MAX;
  leaf_l(root,1,ans);
  cout<<ans<<endl;
  return 0;
}
