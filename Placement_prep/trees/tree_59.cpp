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
typedef struct node{int val;struct node *left;struct node * right;}node;
node * make(int val){node *root = new(node);root->val = val;root->left = NULL;root->right = NULL;return root;}
void trav(node * root){if(root==NULL)return;cout<<root->val<<"\t";trav(root->left);trav(root->right);}
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}

int levl(int u,node *root,int level,node * obj)
{
  if(root==NULL)
    return 0;
  if(root->val==u)
    {
      obj = root;
      return level;
    }
  return levl(u,root->left,level+1,obj) + levl(u,root->right,level+1,obj);
}
bool sibling(node *root,node *u,node *v)
{
  if(root==NULL)
    return false;
   if((root->left==u && root->right==v) ||(root->left==v && root->right==u))
    return true;
   return (sibling(root->left,u,v) ||sibling(root->right,u,v));
}
int  main()
{
  node * root = init(root);
  node *u_ref,*v_ref;
  if((levl(3,root,0,u_ref) == levl(6,root,0,v_ref)) && !sibling(root,u_ref,v_ref))
        cout<<"Cousins\n";
  else
      cout<<"Not cousins\n";

  return 0;
}
