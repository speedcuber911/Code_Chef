#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;
 typedef struct node
 {
   int val;
   node*next;
 }node;

 typedef struct Queue
 {
   node *front,*rear;
 }Queue;

Queue *init(Queue *q)
{
  q = new(Queue);
  q->front = NULL;
  q->rear = NULL;
  return q;
}

node *init_l(node *head,int val)
{
  head = new (node);
  head->next = NULL;
  head->val = val;
  return head;
}
node * _append(node * head,int val)
{
  while(head->next!=NULL)
    {
      head = head->next;
    }
    node * temp = new (node);
    head->next = temp;
    temp->val = val;
    temp->next = NULL;
    return temp;
}
void _push_back(Queue *q,int n)
{

      if(q->front == NULL)
        {
          node * head = init_l(head,n);
          q->front  = head;
        }
      else
      {
        q->rear = _append(q->front,n);
      }
}
void pop(Queue *q)
{
  if(q->front==NULL)
    cout<<"Empty Queue";
  q->front = q->front->next;
}
void front(Queue *q)
{
  cout<<q->front->val<<endl;
}
void rear(Queue *q)
{
  cout<<q->rear->val<<endl;
}
 int main()
 {
   Queue *q = init(q);
   _push_back(q,0);
   _push_back(q,1);
   _push_back(q,2);
   _push_back(q,3);
   _push_back(q,4);
   for(int i=0;i<4;i++)
    pop(q);
    pop(q);
  //  front(q);
   rear(q);
   return 0;
 }
