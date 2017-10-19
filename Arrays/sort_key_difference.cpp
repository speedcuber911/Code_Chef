#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void rearrange(vector<int>&arr,int x)
{
    multimap<int,int>m;
    for(int i=0;i<arr.size();i++)
        m.insert(make_pair(abs(x-arr[i]),arr[i])) ;
    int i=0;
    for(auto it=m.begin();it!=m.end();++it)
        arr[i++] = it->second;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int x;
  cin>>x;
  rearrange(arr,x);
  return 0;
}
