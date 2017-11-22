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
  int top;
  int area;
  int max_area = -1;
  int i=0;
  while(i<n)
  {
    if(st.empty() || arr[st.top()] <= arr[i])
      st.push(i++);
    else
    {
        top = st.top();
        st.pop();
        if(st.empty())
          area = arr[top]*i;
        else
          area  = arr[top]*(i-st.top()-1);
        max_area = max(area,max_area);
    }
  }
  while(!st.empty())
  {
    top  = st.top();
    st.pop();
    if(st.empty())
      area = arr[top]*i;
    else
      area  = arr[top]*(i-st.top()-1);
    max_area = max(area,max_area);
  }
  cout<<max_area<<endl;
  return 0;
  }
