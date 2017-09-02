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

void add_after(node *head,int val2)
{
    node * temp = new (node);
    temp->next = head->next;
    head->next = temp;
    temp->val = val2;

}
void add_before(node * head,int val)
{
  node * temp = new (node);
  while(head->val!=val && head->next!=NULL)
  {
      head = head->next;
  }
  temp->val = val;
  temp->next = head->next;
  head->next = temp;
}
node * merge(node * head,node * head2)
{
  if(head==NULL)
    return head2;
  if(head2==NULL)
    return head;
  if(head->val < head2->val)
    {
      head ->next = merge(head->next,head2);
      return head;
    }
  else
  {
    head2->next = merge(head,head2->next)
    return head2;
  }

}
int main()
{
  node * head = init(head,0);
  for(int i=1;i<15;i+=1 )
      if(i%2==0)
        _append_list(head,i);
  node * head2 = init(head2,0);
  for(int i=1;i<15;i+=1)
      if(i%2!=0)
        _append_list(head2,i);
  traverse(head);
  traverse(head2);
  merge(head,head2);
  traverse(head);
  return 0;
}
