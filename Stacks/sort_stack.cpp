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

void put_under(stack<int>&s,int item)
{
  if(s.empty() || s.top()<item)
    {
    s.push(item);
    return;
    }
  int a = s.top();
  s.pop();
  put_under(s,item);
  s.push(a);
}
void sort(stack<int>&s)
{
  if(s.empty())
    return;
  int a  = s.top();
  s.pop();
  sort(s);
  put_under(s,a);
}
int main()
{
  stack<int>s;
  s.push(1);
  s.push(2);
  s.push(-3);
  s.push(0);
  sort(s);
  while(!s.empty())
    {
      cout<<s.top()<<endl;
      s.pop();
    }
  return 0;
}
