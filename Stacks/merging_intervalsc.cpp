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

typedef struct interv{
  int start;
  int end;
}interv;

bool compare(interv i1, interv i2)
{
    return (i1.start < i2.start);
}
int main()
{
  int n;
  cin>>n;
  vector<interv>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i].start>>arr[i].end;
  sort(arr.begin(),arr.end(),compare);
  stack<interv>st;
  st.push(arr[0]);
  interv temp;
  for(int i=1;i<n;i++)
  {
    temp = st.top();
    if(temp.end>arr[i].start)
      {
          st.pop();
          interv temp2 = temp;
          if(temp.end> arr[i].end)
              temp2.end = temp.end;
          else
              temp2.end = arr[i].end;
          st.push(temp2);//merged
      }
    else
        st.push(arr[i]);//
  }
  vector<interv>v;
  while(!st.empty())
  {
    v.push_back(st.top());
    // cout<<st.top().start<<" "<<st.top().end<<endl;
    st.pop() ;
  }
  for(int i=0;i<n;i++)
    cout<<v[i].start<<v[i].end;
  return 0;
}
