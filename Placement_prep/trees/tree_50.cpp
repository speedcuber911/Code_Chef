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

int min_(int x,int y)
{
  if(x>y)
    return x;
  return y;
}
void fill(node * root ,int key,vector<node *>&rev)
{
  // cout<<"Adding"<<root->val<<"\n";
  if(root==NULL)
    return;
  rev.push_back(root);
  if(root->val==key)
      return ;
  fill(root->left,key,rev);
  fill(root->right,key,rev);
}
int dist(node * root)
{
  if(root==NULL)
    return 0;
  if(root->left == NULL && root->right == NULL)
    return 0;
  return  min( 1+dist(root->left) , 1+dist(root->right) ) ;
}
int main()
{
    node *root        = make('A');
    root->left               = make('B');
    root->right              = make('C');
    root->right->left        = make('E');
    root->right->right       = make('F');
    root->right->left->left  = make('G');
    root->right->left->left->left  = make('I');
    root->right->left->left->right = make('J');
    root->right->right->right      = make('H');
    root->right->right->right->left = make('K');
    char key;
    cin>>key;
    vector<node * >rev;
    fill(root,key,rev);
    int res = INT_MAX;
    for(int i=0;i<rev.size();i++)
        {
          node * temp = rev[i];
          // cout<<temp->val<<"\t";
          if(temp->left != NULL || temp->right != NULL)// && temp->val!=key)
              cout<<temp->val<<"\t"<<dist(rev[i])<<"\n";
            // res = min(dist(rev[i]),res);
        }
    // cout<<res<<endl;
  return 0;
}
