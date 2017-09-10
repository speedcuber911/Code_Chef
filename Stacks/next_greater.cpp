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
  //O(n^2) approach does exist brute force, else using stack
  int arr[] = {11,13,21,3};
  int n =4;
  int element,next;
  stack<int>s;
  s.push(arr[0]);
  for(int i=1;i<n;i++)
  {
    next = arr[i];
    if(!s.empty())
    {
      element  = s.top();
      s.pop();
      while(element < next)
      {
        cout<<element<<"-->"<<next<<endl;
        if(s.empty())
          break;
        element = s.top();
        s.pop();
      }
      if(element > next)
        s.push(element);
    }
    s.push(next);
  }
  while(!s.empty())
  {
    cout<<s.top()<<"--> -1"<<endl;
    s.pop();
  }
  return 0;
}
