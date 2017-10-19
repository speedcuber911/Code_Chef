#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

void max_min(int arr[],int n)
{

  int start=0,end=n-1;
  int max_=arr[end]+1;
  for (int i = 0; i < n; i++)
  {
    if(i%2==0)
      arr[i]+=arr[end--]%max_*max_;
    else
      arr[i]+=arr[start++]%max_*max_;

  }
  for (int i = 0; i < n; i++)
    arr[i]/=max_;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++)
    arr[i]=i+1;
  max_min(arr,n);
  for (int i = 0; i <n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}
