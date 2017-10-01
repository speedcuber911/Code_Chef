#include <iostream>
// #include <bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;

int main()
{

  int n;
  cin>>n;
  string a ;
  int ctr=0;
  while(n--)
  {
    cin>>a;
    cout<<a.length()<<endl;
    stack<char>s;
    s.push(a[0]);
    for(int i=1;i<a.length();i++)
    {

      if(!s.empty())
        {
          if(s.top()==a[i])
          s.pop();
        }
      else
        s.push(a[i]);
    }
    if(s.empty())
      ctr++;

  }
  cout<<ctr<<endl;
  return 0;
}
