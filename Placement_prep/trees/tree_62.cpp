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

bool op(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}
node *tree_maker(string a)
{
  stack<node *>st;

  for(int i=0;i<a.length();i++)
  {
    if(!op(a[i]))
      st.push(make(a[i]));
    else
    {
      node * t1 = make(a[i]);
      node * t2 = st.top();
      st.pop();
      node * t3 = st.top();
      st.pop();
      t1->right = t2;
      t1->left = t3;
      st.push(t1);
    }
  }
  node * r = st.top();
  st.pop();
  return r;
}


node * parse_tree(string a,int beg,int end)
{
  if(beg==end)
  {
    return NULL;
  }
  int mid = (beg + end)/2;
  node * temp  = make(a[mid]);
  temp ->left = parse_tree(a,beg,mid);
  temp->right = parse_tree(a,mid+1,end);
  return temp;
}
int main()
{
    string a  = "ab+ef*g*-";
    node * root = tree_maker(a);
    // trav(parse_tree(a,0,9));
    return 0;
}
