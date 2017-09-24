#include<utility>
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

int vertical_order_sum(node * root,int hd,int i,string &sum)
{
  if(root==NULL)
    return 0;
  if(i==hd)
    {
    sum.append(to_string(root->val));
    }
  vertical_order_sum(root->left,hd,i-1,sum);
  vertical_order_sum(root->right,hd,i+1,sum);
}
void hor_dist(node * root,int hd,int &l,int &r)
{
  if(root==NULL)
    return;
    l = min(hd,l);
    r = max(hd,r);
  hor_dist(root->left,hd-1,l,r);
  hor_dist(root->right,hd+1,l,r);
}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  int l=0,r=0;
  hor_dist(root,0,l,r);
  int num_sum = 0;
  // cout<<l<<" "<<r<<endl;-=
  for(l;l<=r;l++)
    {
    string sum;
    vertical_order_sum(root,l,0,sum);
    // cout<<sum<<endl;
    num_sum += stoi(sum);
    }
  cout<<num_sum;  
  return 0;
}
