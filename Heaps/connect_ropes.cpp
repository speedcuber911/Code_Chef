#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

void min_heapify(int arr[],int n,int i)
{
  int l = 2*i+1;
  int r = 2*(i+1);
  int smallest = i;
  if(arr[smallest] > arr[l] && l < n)
    smallest = l;
  if(arr[smallest] > arr[r] && r < n)
    smallest = r;
  if(smallest!=i)
    {
      swap(arr[smallest],arr[i]);
      min_heapify(arr,n,smallest);
    }
}
void heap_stat(int arr[],int n)
{
  cout<<"Printing heap \n";
  for(int i=0;i<n;i++)
    cout<<arr[i]<<"---> ";
}
int extract_min(int arr[],int &n)
{
  int temp = arr[0];
  swap(arr[0],arr[n-1]);
  n--;
  min_heapify(arr,n,0);
  return temp;
}
void h_append(int arr[],int &n,int r)
{
    n++;
    arr[n-1] = r;
    min_heapify(arr,n,0);
}
int collapse(int arr[],int &n)
{
  int t = extract_min(arr,n);
  int s = extract_min(arr,n);
  cout<<"appending "<<s<<" + "<<t<<" = "<<s+t<<endl;
  h_append(arr,n,s+t);
  return(s+t);
}

int cost(int arr[],int n)
{
  for(int i=(n/2-1);i>=0;i--)
    min_heapify(arr,n,i);
  int costed=0;
  while(n!=1)
    {
      costed += collapse(arr,n);
    }
  return costed;
}
int main()
{
  int arr[] = {4,2,3,6};
  cout<<cost(arr,4)<<endl;
  return 0;
}
