#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<unordered_set>
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
        _append_list(head,val+i);
      else
        _append_list(head,val+14-i);
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
void remove_dup(node * head)
{
  map<int,int>a;
  node *prev=NULL,*cur=head;
  while(cur->next!=NULL)
  {
    if(a[cur->val]==1)
    {
      prev->next = cur->next;
      delete(cur);
      cur = cur->next;
    }
    if(a[cur->val]==0)
    {
      a[cur->val]=1;
      prev = cur;
      cur = cur->next;
    }
  }
}
int main()//removing duplicates form an usnorted list
{
  node * head;
  head = init(head,0);
  traverse(head);
  remove_dup(head);
  traverse(head);
  return 0;
}
