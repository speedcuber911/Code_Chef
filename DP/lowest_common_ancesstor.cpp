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

tnode * newNode(int val)
{
  tnode * temp = new(tnode);
  temp->left = NULL;
  temp->right = NULL;
  temp->lis = 0;
  return temp;
}

tnode* find(int key1,int key2,tnode * root)
{
  if(root==NULL)
    return NULL;
  if(root->val == key1 || root->val == key2)
    return root;
  tnode * left_  = find(key1,key2,root->left);
  tnode * right_ = find(key1,key2,root->right);
  if(left_ !=NULL && right_!=NULL)
    return root;
  return (left_!=NULL)?left_:right_;
}

int main()
{
  int key1,key2;
  cin>>key1>>key2;
 Node * root = newNode(1);
 root->left = newNode(2);
 root->right = newNode(3);
 root->left->left = newNode(4);
 root->left->right = newNode(5);
 root->right->left = newNode(6);
 root->right->right = newNode(7)
 find(key1,key2,root);
 return 0;
}
