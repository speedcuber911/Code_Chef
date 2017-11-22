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
  int el,next;
  st.push(arr[0]);
  for(int i=arr.size()-1;i>=0;i--)
  {
    next = arr[i];
  }
  return 0;
}
