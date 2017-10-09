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
      _append_list(head,val+i);
    return head;
}
node * reverse(node * head)
{
  node * prev = NULL,*curr,*next;
  curr = head;
  while(curr!=NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
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
void delete_greater(node * head)
{
  node * temp = reverse(head);
  // traverse(temp);
  node * prev  = NULL;
  int maxed = INT_MIN;
  while(temp->next!=NULL)
  {
    if(temp->val > maxed)
      maxed = temp->val;
    prev = temp;
    temp = temp->next;
    if(temp->val < maxed)
      {
        node * t = temp;
        prev->next = temp->next;
        
        delete(temp);
        temp = prev;
      }
  }
}
int main()
{
  node * head = new (node);
  head->next = NULL;
  head->val = 12;
  // _append_list(head,12);
  _append_list(head,15);
  _append_list(head,10);
  _append_list(head,11);
  _append_list(head,5);
  _append_list(head,6);
  _append_list(head,2);
  _append_list(head,3);
  node * temp = head;
  delete_greater(head);
  traverse(temp);
  return 0;
}
