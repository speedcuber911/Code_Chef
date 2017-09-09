#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

typedef struct Queue{
  int rear,front,size;
  unsigned int capacity;
  int *arr;
}Queue;
Queue *init(Queue *q,unsigned capacity)
{
  q = new(Queue);
  q->capacity = capacity;
  q->front = 0;
  q->size  = 0;
  q->rear = q->capacity -1;
  q->arr = new int[q->capacity];
  return q;
}
int full(Queue* q)
{
  return (q->size == q->capacity);
}

void insert(Queue *q,int n)
{
  if(full(q))
    return ;
   q->rear = (q->rear + 1)%q->capacity;
   q->arr[q->rear] = n;
   q->size = q->size+1;
}
int empty( Queue* q)
{
  return (q->size == 0);
}
void deque(Queue *q,int n)
{
  if(empty(q))
    return;
  else
    {
          int i = q->arr[q->front];
          q->front = (q->front+1)%q->capacity;
          q->size-=1;
    }
}
int rear(Queue *q)
{
  if(empty(q))
    return INT_MIN;
  else
      return q->arr[q->rear];
}
int front(Queue *q)
{
  if(empty(q))
    return INT_MIN;
  else
      return
        q->arr[q->front];
}
int main()
{
  Queue *q = init(q,5);
  insert(q,1);
  insert(q,2);
  insert(q,3);
  insert(q,4);
  insert(q,5);
  cout<<front(q)<<endl;
  cout<<rear(q)<<endl;
  return 0;
}
