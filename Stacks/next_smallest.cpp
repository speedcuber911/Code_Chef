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
  vector<int> a = arr;
reverse(a.begin(),a.end());
stack<int>st;
st.push(a[0]);
int el,next;
vector<int>sized;
for(int i=1;i<a.size();i++)
{
    next = a[i];
    if(!st.empty())
    {
        el = st.top();
        st.pop();
        while(next < el)
        {
            sized.push_back(next);
            cout<<el<<" has next "<<next<<endl;
            if(st.empty())
                break;
            el = st.top();
            st.pop();
        }
        if(next > el)
            st.push(el);
    }
    st.push(a[i]);
}
while(!st.empty())
  {
    cout<<st.top()<<" has next "<<-1<<endl;
    sized.push_back(-1);
    st.pop();
  }
reverse(sized.begin(),sized.end());
for(int i=0;i<a.size();i++)
  cout<<sized[i]<<"\t";
  return 0;
}
