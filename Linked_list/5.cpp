#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

typedef struct node{
  int val;
  struct node * next;
}node;

void _append_list(node * head,int val)
{
  while(head->next!=NULL)
    head = head->next;
  node * temp = new (node);
  head->next = temp;
  temp->next = NULL;
  temp->val = val;
  cout<<"Appended: "<<val<<endl;
}

node * init(node * head,int val)
{
    cout<<"Initilasied\n";
    head = new(node);
    head->val = val;
    head->next = NULL;
    for(int i=1;i<15;i++)
      if(i<8)
        _append_list(head,i);
      else
        _append_list(head,14-i);
    return head;
}
void traverse(node * head)
{
  if(head!=NULL)
  while(head!=NULL)
    {
      cout<<head->val<<"->";
      head= head->next;
    }
  else
    cout<<"Empty";
    cout<<endl;
}
node *reverse(node * head)
{
  node *a,*b,*c;
  a = NULL;
  b = head;
  c = head;
  while(b!=NULL)
  {
    c = b->next;
    b->next = a;
    a = b;
    b = c;
  }
  return a;
}
void ispalin(node *head)
{
  node *slow=head,*fast=head;
  bool flip = true;
  while(fast!=NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  if(fast==NULL)
    {
    node *rev = reverse(slow);
    while(rev!=NULL)
    {
      if(rev->val == head->val)
      {
        rev = rev->next;
        head = head->next;
      }
      else
      {
        rev = rev->next;
        head = head->next;
        flip = false;
      }
    }
    if(flip)
      cout<<"Palindromic";
    else
      cout<<"Not Palindromic";
    }
    else
    {
      node *rev = reverse(slow);
      while(rev->next!=NULL)
      {
        if(rev->val == head->val)
        {
          rev = rev->next;
          head = head->next;
        }
        else
        {
          rev = rev->next;
          head = head->next;
          flip = false;
        }
      }
      if(flip)
        cout<<"Palindromic";
      else
        cout<<"Not Palindromic";
      }
    }
int main()//Palindromic list
{
  node * head;
  head = init(head,0);
  traverse(head);
  ispalin(head);
  return 0;
}
