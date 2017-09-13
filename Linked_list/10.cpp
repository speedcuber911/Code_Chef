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
    for(int i=15;i>0;i--)
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
node * reverse(node * head)
{
  node * prev=NULL,*cur= head,*next;
  while(cur!=NULL)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}
node * del_g_nodes(node *head)
{
  head = reverse(head);
  node * cur = head;
  node * max = head;
  node * temp;
  while(cur!=NULL && cur->next!=NULL)
  {
    if(cur->next->val < max->val)
    {
      temp = cur->next;
      cur->next = temp->next;
      free(temp);
    }
    if(cur->next->val > max->val)
    {
      cur  = cur->next;
      max = cur;
    }
  }
  head = reverse(head);
  return head;
}
int main()//Delete nodes with greater value on right side
{
  node * head;
  head = init(head,0);
  // traverse(reverse(head));
  head = del_g_nodes(head);
  traverse(head);
  return 0;
}
