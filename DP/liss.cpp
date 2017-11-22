#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;

typedef struct tnode{
  int val;
  tnode* left;
  tnode* right;
  int lis;
}tnode;

tnode * new_t(int val)
{
  tnode * temp = new(tnode);
  temp->left = NULL;
  temp->right = NULL;
  temp->lis = 0;
  return temp;
}

int liss(tnode * root)
{
  if(root == NULL)
    return 0;
  if(root->lis!=0)
    return root->lis;
  int excl = 0;
  excl =  (liss(root->left) + liss(root->right));
  int incl = 1;
  if(root->left!=NULL)
    incl += (liss(root->left->left) + liss(root->left->right));
  if(root->right!=NULL)
    incl += ( liss(root->right->left) + liss(root->right->right));
  root->lis = max(incl,excl);
  return root->lis;
}
int main()
{
  tnode * root;
  root = new_t(10);
  root->left = new_t(20);
  root->right = new_t(30);
  root->right->right = new_t(60);
  root->left->left = new_t(90);
  root->left->right = new_t(50);
  root->left->right->left = new_t(70);
  root->left->right->right = new_t(60);
  cout<<liss(root);
}
