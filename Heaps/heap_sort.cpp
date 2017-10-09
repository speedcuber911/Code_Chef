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

void max_heapify(vector<int>& arr,int i,int size)
{
  // cout<<"Working on "<<arr[i]<<endl;
  int l = (2*i) + 1;
  int r = 2*(i+1);
  // if(l < size && r < size)
    // cout<<" with kids as "<<arr[l]<<" "<<arr[r]<<endl;
  // else
    // cout<<" Its leaf, they dont have kids, man\n";
  int largest = i;
  if(l < size && arr[l] > arr[largest])
    largest = l;
  if(r < size && arr[r] > arr[largest])
    largest = r;
  if(i!=largest)
  {
    swap(arr[i],arr[largest]);
    max_heapify(arr,largest,size);
  }
}
void heap_sort(vector<int>&arr)
{
  for(int i=(arr.size()/2-1);i>=0;i--)
    max_heapify(arr,i,arr.size());
  for(int i = arr.size()-1;i>=0;i--)
      {
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i);
      }
}
int main()//Looks good, easy too, I get most of it now, but still not perfect
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<arr.size();i++)
    cin>>arr[i];
  heap_sort(arr);
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  return 0;
}
