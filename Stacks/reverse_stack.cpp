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
  if(s.empty())
    s.push(item);
  else
  {
    int a = s.top();
    s.pop();
    put_under(s,item);
    s.push(a);
  }
}
void rev(stack<int>&s)
{
  if(s.empty())
    return;
  int a  = s.top();
  s.pop();
  rev(s);
  put_under(s,a);
}
int main()
{
  stack<int>s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  rev(s);
  while(!s.empty())
    {
      cout<<s.top()<<endl;
      s.pop();
    }
  return 0;
}
