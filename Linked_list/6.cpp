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
      _append_list(head,i);
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
void remove_duplicates(ListNode * head)
{
    ListNode *temp = head->next;
    ListNode * temp2 =head;
    while(head->next!=NULL)
    {
      if(head->val == temp->val)
        {
          node * haed
          head->next = temp->next;
          temp->next =NULL;
          free(temp);
          temp = head->next;
        }
      else
        {
          head = head->next;
          temp = temp->next;
        }
    }
    while(temp2!=NULL)
      {
        cout<<temp2->val<<" ";
        temp2= temp2->next;
      }
}
int main()
{
  node * head;
  head = init(head,0);
  remove_duplicates(head);
  traverse(head);
  return 0;
}
