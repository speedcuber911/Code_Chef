#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(int i=0;i<n;i+=2)
  {
    if(i>0 && arr[i-1]>arr[i])
      swap(arr[i-1],arr[i]);
    if(i<n-1 && arr[i+1]>arr[i])
      swap(arr[i+1],arr[i]);
  }
  
  return 0;
}
