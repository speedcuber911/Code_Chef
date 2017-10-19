#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void lr(vector<int>&a)
{
  int t = a[a.size()-1];
  for(int i=a.size()-1;i>0;i--)
    a[i] = a[i-1];
  a[0] = t;
}
int main()
{
  int n,d;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cin>>d;
  for(int i=0;i<d;i++)
    lr(arr);
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  return 0;
}
