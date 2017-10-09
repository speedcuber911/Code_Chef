#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>

using namespace std;

void max_heap(vector<int>&arr,int i,int n)
{
  // cout<<"Entered";
  int l = 2*i +1;
  int r = 2*(i+1);
  int largest = i;
  if(l < n && arr[l] > arr[largest])
    largest = l;
  if(r < n && arr[r] > arr[largest])
    largest = l;
  if(i!=largest)
  {
    swap(arr[i],arr[largest]);
    max_heap(arr,largest,n);
  }
}
void disp(vector<int>&arr)
{
  for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
}
void extract_kth(vector<int>&arr,int k)
{
  for(int i=(arr.size()-1);i>=0;i--)
    max_heap(arr,i,arr.size());//heap maker
  for(int i=0;i<k;i++)
  {
    cout<<arr[0]<<endl;
    swap(arr[0],arr[arr.size()-i-1]);
    max_heap(arr,0,arr.size()-i-1);
  }
}
int main()// The top of a max_heap would give the maximum element, do that k times with a reduced heap each time.
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k;
  cin>>k;
  extract_kth(arr,k);
  return 0;
}
