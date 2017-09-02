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
void add_after(node *head,int val,int val2)
{
    while(head->val!=val)
      head = head->next;
    node * temp = new (node);
    temp->next = head->next;
    head->next = temp;
    temp->val = val2;
}
node * _prepend(node *head,int val)
{
  node * temp = new (node);
  temp->val = val;
  temp->next = head;
  return temp;
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
node* remove_p(node * head,int val)
{

  node * temp,*temp2=head;
  if(head->val == val)
    {
        temp =  head->next;
        free(head);
        return (temp);
    }
    else
    {
      while(temp2->val!=val)
      {
        temp = temp2;
        temp2 = temp2->next;
      }
      temp->next = temp2->next;
      free(temp2);
      return head;
    }
  }
  int _linked_DFS(node *head,int n)
  {
    if(head->next ==NULL)
       return n+1;
    else
       return _linked_DFS(head->next,n+1);
  }
  node * _search_list(node * head,int val)
  {
    if(head==NULL)
      return NULL;
    if(head->val==val)
      return head;
    return _search_list(head->next,val);
  }

  node* swap_nodes(node *head,int val1,int val2)
  {
      node *x1=NULL,*x2=head,*y1=NULL,*y2=head;
      while(x2->val!=val1)
        {
          x1 = x2;
          x2 = x2->next;
        }
      while(y2->val!=val2)
        {
          y1 = y2;
          y2 = y2->next;
        }
        if(x1!=NULL)
          x1->next = y2;
        else
          head = y2;
        if(y1!=NULL)
          y1->next = x2;
        else
          head = x2;
        node * tempy = x2->next;
        x2->next = y2->next;
        y2->next = tempy;
        return head;
  }
node *middle_list(node * head)
{
  node * slow=head,*fast=head;
  while(fast!=NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
node * _n_end(node * head,int n)
{
  node * slow=head,* fast=head;
  while(fast->next!=NULL)
  {
      if(n==1)
        {
          slow = slow->next;
          fast= fast->next;
        }
      else
        {
          fast = fast->next;
          n--;
        }
  }
  return slow;
}
node * del_list(node * head)
{
  node * temp=head;
  while(head->next!=NULL)
  {
    temp = head->next;
    free(head);
    head = temp;
  }
  free(head);
  return NULL;
}
node *rev_list(node * head)
{
  node *a,*b,*c;
  a = NULL;
  b = head;
  while(b!=NULL)
  {
    c = b->next;
    b->next = a;
    a = b;
    b = c;
  }
  return a;
}
node * _det_cycle(node * head)
{
  map<node *,int>dict;
  while(dict[head]!=1 && head->next!=NULL)
  {
    dict[head] = 1;
    head = head->next;
  }
  return head;
}
int main()
{
  node * head = init(head,0),*found;
  head = _prepend(head,-1);// To add -1 at the begining  of the list
  add_after(head,4,19);
  head = remove_p(head,19);//works for the 1st element as well!
  cout<<endl<<"Length of linked list: "<< _linked_DFS(head,0)<<endl;//Length of list
  found = _search_list(head,6);
  if(found==NULL)//Searching an element
    cout<<"Not there\n";
  else
    cout<<"Found\n";
  // head = swap_nodes(head,4,8);
  node* middle = middle_list(head);//middle of list
  cout<<"Middle of the linked list: "<<middle->val<<" \n";//print middle
  node * n_end = _n_end(head,3);//n the node from end
  cout<<"The 3 element from end: "<<n_end->val<<" \n";// printing it
  // head = del_list(head);//deletes the list
  head  = rev_list(head);//reverses the linked list
  node * rep = _det_cycle(head);//This et the node with cycle
  cout<<rep->val;//print it
  merge(head);
  // traverse(head);
  return 0;
}
