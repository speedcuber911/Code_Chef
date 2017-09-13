#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool part_utility(int arr[],int r,int n)
{
    if(r == 0 || r == arr[n])
      return true;
    if(n<0)
      return false;
    if(r-arr[n]<0)
      part_utility(arr,r,n-1);
    else
      return (part_utility(arr,r-arr[n],n-1) || part_utility(arr,r,n-1));
}
int partition(int arr[],int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=arr[i];
  cout<<sum<<endl;
  if(sum%2!=0)
    return -1;
  else
    return part_utility(arr,sum/2,4);
}
int main()
{
  int arr[5] = {3, 1, 5, 9, 12};
  if(partition(arr,5))
    cout<<"yes\n";
  else
      cout<<"no\n";
  return 0;
}
