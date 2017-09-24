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

void leaf_list(node * root)
{

}
int main()
{
  node * root = init(root);//makes  a 0-6 tree
  list_node()
  return 0;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  int less=INT_MAX,more=INT_MIN;
  bool flip =0;
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
      if((m-a[i])>0)
        {
          if(a[i]>more)
            more = a[i];
        }
      if(a[i]<less)
        less = a[i];
      if(a[i]>m && !flip)
        {
        flip =1;
        more = a[i];
        }
  }

  return 0;
}
