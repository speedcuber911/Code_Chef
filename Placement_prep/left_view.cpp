#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>

using namespace std;

void solve(node *root)
{
  if(!root)
    return;
  if(!root->left)
    cout<<root->left->val<<" ";
  solve(root->left);
  solve(root->right);
}

void solve(node * root)
{
  queue<node *>qu;
  qu.push(root);
  qu.push(NULL);
  cout<<root->val;
  while(!qu.empty())
  {
    node * temp  = qu.front();
    qu.pop();
    if(!temp)
      {
        qu.pop();
        qu.push(NULL);
      }
    if(temp->left)
      qu.push(temp->left);
    if(temp->right)
      qu.push(temp->right);
  }

}
int main()
{
  cout<<root->val<<" ";
  solve(root);
}
