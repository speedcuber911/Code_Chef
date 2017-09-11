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
  // cout<<"Appended: "<<val<<endl;
}

node * init(node * head,int val)
{
    cout<<"Initialised\n";
    head = new(node);
    head->val = val;
    head->next = NULL;
    for(int i=1;i<5;i++)
      _append_list(head,val+i);
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
node * intersect(node * head,node* head2)
{
  node *temp = new (node);
  temp->next = NULL;
  while(head!=NULL && head2!=NULL)
  {
    if(head->val == head2->val)
    {
      cout << head->val << " " << head2->val << endl;
      _append_list(temp,head->val);
      head = head->next;
      head2 = head2->next;
    }
    if(head->val > head2->val)
    {
      head2 = head2->next;
    }
    if((head->val < head2->val))
    {
      if(head->next!=NULL)
      head = head->next;
    }

  }

  return (temp->next);
}
int main()//Intersection of 2 sorted lists
{
  node * head,*head2;
  head = init(head,0);
  head2 = init(head2,1);
  traverse(head);
  traverse(head2);
  node * dum = intersect(head,head2);
  traverse(dum);
  return 0;
}
