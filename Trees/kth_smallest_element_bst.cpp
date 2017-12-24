#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void solve(vector<int>arr,int k,int i,int &ans,int &ans2)
{
  if(i > arr.size()-1)
    return;
  solve(arr,k,2*i+1,ans,ans2);
  if(++ans == k)
    ans2 = arr[i];
  solve(arr,k,2*(i+1),ans,ans2);
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int ans2;
  int k;
  cin>>k;
  int ans = 0;
  solve(arr,k,0,ans,ans2);
  cout<<ans2<<endl;
  return 0;
}
