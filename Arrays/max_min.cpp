#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void rearrange(vector<int>arr)
{
  vector<int>brr(arr.size()-1);
  int end = arr.size()-1;
  int start =0;
  for(int i=0;i<arr.size();i++)
    if(i%2==0)
      brr[i] = arr[end--];
    else
      brr[i] = arr[start++];
  for(int i=0;i<arr.size();i++)
    cout<<brr[i]<<" ";
  cout<<endl;  
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  rearrange(arr);
  return 0;
}
