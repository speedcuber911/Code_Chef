#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<queue>

using namespace std;

void push_s(queue<int> &a,int x)
{
  int size = a.size();
  if(a.size()==0)
    a.push(x);
  else
  {
    while(size!=0)
    {
      a.push(a.front());
      a.pop();
      size--;
    }
  }
}
int main()
{
  queue<int>s;
  // cout<<"size is "<<s.size();
  for(int i=1;i<7;i++)
    push_s(s,i);
  cout<<s.front();
}
