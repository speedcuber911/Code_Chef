#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<stack>

using namespace std;

int push1(int arr[],int x,int head)
{
  if(head>9)
    cout<<"overflow\n";
  else
    arr[head] = x;
  return(++head);
}
int push2(int arr[],int x,int head2)
{
  if(head2<0)
    cout<<"overflow\n";
  else
    arr[head2] = x;
  return(--head2);
}
int pop1(int arr[],int head)
{
  if(head==0)
    cout<<"Underflow\n";
  else
    cout<<arr[--head]<<endl;
  return 0;
}
int  pop2(int arr[],int head2)
{
  if(head2==9)
    cout<<"Underflow\n";
  else
    cout<<arr[++head2]<<endl;
  return 0;
}
int main()
{
  int arr[10];
  int head = 0,head2 = 9;
  head = push1(arr,1,head);
  head2 = push2(arr,7,head2);  
  pop1(arr,head);
  pop2(arr,head2);
  return 0;
}
