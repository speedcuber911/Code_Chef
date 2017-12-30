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
node * init(node * root){root = make(0);root->right  = make(2);root ->left = make(1);root->left->left = make(3);root->left->right  = make(4);root->right->left  = make(5);root->right->right  = make(6);return root;}
void trav(node * root){if(root==NULL)return;trav(root->left);cout<<root->val<<"\t";trav(root->right);}

int main()
{
  node * root = init(root);//makes  a 0-6 tree
  stack<node * >st;
  int x = 8;
  st.push(root);
  while(!st.empty())
  {
    node * temp = st.top();
    st.pop();
    cout<<temp->val<<"\t";
    if(temp->val == x)
      {
        cout<<temp->val<<"\t";
        break;
      }
    if(temp->right)
      st.push(temp->right);
    if(temp->left)
      st.push(temp->left);
  }
  cout<<endl;
  return 0;
}
