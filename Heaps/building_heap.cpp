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


void max_heapify(int arr[],int i,int size)
{
  // cout<<"Working on "<<arr[i]<<endl;
  int l = (2*i) + 1;
  int r = 2*(i+1);
  // if(l < size && r < size)
    // cout<<" with kids as "<<arr[l]<<" "<<arr[r]<<endl;
  // else
    // cout<<" Its leaf, they dont have kids, man\n";
  int largest = i;
  if( l < size && arr[largest] < arr[l] )
    largest = l;
  if( r < size && arr[largest] < arr[r] )
    largest = r;
  // cout<<"\n larget now as "<<arr[largest]<<endl;
  if(i!=largest)
    {
      swap(arr[i],arr[largest]);
      max_heapify(arr,largest,size);
    }
}
int main()// Okay heaps make more sense now, an array can be converted into a heap
// Also i sense a strong relation between heap and seg tree now
{
  // int n;
  // cin>>n;
  // vector<int>arr(n);
  int arr [7] = {4,5,6,7,8,9,10};
  int n=7;
  int j=1;
  for(int i = (n/2-1);i>=0;i--)
    {
      // cout<<"Processing "<<arr[i]<<" th\n\n";
      max_heapify(arr,i,7);
      j++;
    }
  for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";
}
