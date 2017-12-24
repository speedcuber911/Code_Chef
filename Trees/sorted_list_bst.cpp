#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

typedef struct node{
  struct node* next;
  int val;
}node;

typedef struct tnode{
  struct tnode * left;
  struct tnode * right;
  int val;
}tnode;

void _append_list(node * head,int val)
{
  while(head->next!=NULL)
    head = head->next;
  node * temp = new (node);
  head->next = temp;
  temp->next = NULL;
  temp->val = val;
}
tnode * newNode(int val)
{
    tnode * temp = new(tnode);
    temp->left = NULL;
    temp->right = NULL;
    temp->val = val;
    return temp;
}

tnode * list_tree(node ** head,int start,int end)
{
  if(start>end)
    return NULL;
  int mid = (start+end)/2;
  tnode * left_ = list_tree(head,start,mid-1);
  tnode *root = newNode((*head)->val);
  root->left = left_;
  *head = (*head)->next;
  root->right = list_tree(head,mid+1,end);
  return root;
}
void trav(tnode * root)
{
  cout<<"entered";
  if(root==NULL)
    return;
  trav(root->left);
  cout<<root->val<<"  ";
  trav(root->right);
}
int main()
{
  node * head = new(node);
  head->next = NULL;
  head ->val = 1;
  int n;
  cin>>n;
  int temp;
  while(n--)
  {
    cin>>temp;
    _append_list(head,temp);
  }
  tnode * root = list_tree(&head,0,n);
  trav(root);
  return 0;
}
