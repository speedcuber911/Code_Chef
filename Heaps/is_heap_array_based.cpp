#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

bool heap(int arr[], int i, int n)
{

   if (i > (n - 2)/2)
       return true;
   if (arr[i] >= arr[2*i + 1]  &&  arr[i] >= arr[2*i + 2] &&
       isHeap(arr, 2*i + 1, n) && isHeap(arr, 2*i + 2, n))
       return true;

   return false;
}
int main()
{
  int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
  if(heap(arr,n))
    cout<<"YES\n";
  else
    cout<<"NO\n";
  return 0;
}
