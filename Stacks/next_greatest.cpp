#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  stack<int>st;
  st.push(arr[0]);
  int el,next;
  vector<int>posser;
  for(int i=1;i<arr.size();i++)
  {
    next = arr[i];
    if(!st.empty())
    {
      el = st.top();
      st.pop();
      while(el < next)
      {
        cout<<next<<" is greatest for "<<el<<endl;
        if(st.empty())
          break;
        el = st.top();
        st.pop();
      }
      if(el > next)
        st.push(el);
    }
    st.push(next);
  }  
  while(!st.empty())
  {
    cout<<" -1\n";
    st.pop();
  }
  return 0;
}
