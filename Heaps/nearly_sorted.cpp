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
int replace(int arr[],int n,int new_el)
{
  int temp = arr[0];
  arr[0] = new_el;
  if(temp < new_el)
    min_heapify(arr,n,0);
  return temp;
}
int extract_min(int arr[],int &n)
{
  int temp = arr[0];
  swap(arr[0],arr[n-1]);
  n--;
  min_heapify(arr,n,0);
  return arr[0];
}
void sortK(int arr[],int n,int k)
{
    k++;
    int h_tree[k];
    for(int i=0;i<k;i++)
      h_tree[i] = arr[i];
    for(int i= (n/2-1);i>=0;i--)
      min_heapify(h_tree,k,i);
    int ti = 0,i=k;
    for(int ti=0;ti<n;ti++)
      {
        if(i<n)
          arr[ti] = replace(h_tree,k,arr[i]);
        else
          {
            arr[ti] = extract_min(h_tree,k);
            cout<<arr[ti]<<"THis one\n";
          }
        i++;
      }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()// A slight error, would fix it, once I get back in the headspace.
{
  int k=3;
  int arr[] = {2, 6, 3, 12, 56, 8};
  int n = 6;
  sortK(arr,n,k);
  return 0;
}
