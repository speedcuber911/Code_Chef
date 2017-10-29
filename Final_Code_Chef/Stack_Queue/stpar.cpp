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

int main()
{
  for(;;)
  {
  int n;
  cin>>n;
  if(n==0)
    break;
  bool flag =1;
  stack<int>s;
  vector<int>ar;
  int x;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    while(!s.empty() && s.top()<x)
    {
      ar.push_back(s.top());
      s.pop();
    }
    s.push(x);
  }
  while(!s.empty())
    {
      ar.push_back(s.top());
      s.pop();
    }
  for(int i=0;i<ar.size();i++)
      if(ar[i] != i+1)
        {
          flag=0;
          break;
        }
  if(flag)
    cout<<"yes\n";
  else
    cout<<"no\n";
  }
  return 0;
}
