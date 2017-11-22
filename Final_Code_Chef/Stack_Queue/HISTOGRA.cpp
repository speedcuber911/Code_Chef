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

int  main()
{
  for(;;)
  {
  long long int  n;
  cin>>n;
  if(n==0)
    break;
  vector<long long int >arr(n);
  for(long long int  i=0;i<n;i++)
    cin>>arr[i];
  stack<long long int >st;
  long long int  area,max_ar = -1;
  long long int  i=0;
while(i<n)
{
  if(st.empty() || arr[i] > arr[st.top()])
    {
      st.push(i);
      i++;
    }
  else
  {
    long long int  top = st.top();
    st.pop();
    if(!st.empty())
      area = arr[top]*(i-st.top()-1);
    else
      area = arr[top]*(i);
    max_ar = max(area,max_ar);
  }
}
while(!st.empty())
{
  long long int  top = st.top();
  st.pop();
  if(!st.empty())
    area = arr[top]*(i-st.top()-1);
  else
    area = arr[top]*(i);
  max_ar = max(area,max_ar);
}
cout<<max_ar<<"\n";
}
return 0;
}
