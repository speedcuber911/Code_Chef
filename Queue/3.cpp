#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

typedef struct stack
{
  int data;
  stack *next;
} stack;

typedef struct queue
{
  stack *s1,*s2;
}queue;
stack *push(stack *s , int x)
{

  stack *new_node = new(stack);
  new_node->data  = x;
  new_node -> next = s;
  s = new_node;
  return s;
}
int pop(stack *s)
{
  int res;
  stack *top;
  top = s;
  res = top->data;
  s = top->next;
  free(top);
  return res;
}
void enqueue(queue *q,int x)
{
  q->s1 = push(q->s1,x);
}
int dequeue(queue *q)
{
  int x;
  if(q->s1 ==NULL && q->s2 ==NULL)
      exit(0);
  if(q->s2==NULL)
    while(q->s1!=NULL)
      {
        x = pop(q->s1);
        push(q->s2,x);
      }
  x = pop(q->s2);
  return x;
}
int main()
{
    queue *q = new(queue);
    q->s1 = NULL;
    q->s2 = NULL;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    cout<<dequeue(q);
}
