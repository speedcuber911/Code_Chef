#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void rearrange(int arr[]),int n)
{
  int k=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]<0)
      {
        swap(arr[i],arr[k]);
        k++;
      }
  }
  int pos_p = k+1;
  int i=0;
  while(pos_p < n && i < pos_p && arr[i]<0)
  {
    swap(arr[i],arr[pos_p]);
    pos_p++;
    i+=2;
  }
}
int main()
{
  int arr[9] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
  rearrane(arr,n);
  return 0;
}
