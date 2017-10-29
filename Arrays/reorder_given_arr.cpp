#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

void reorder(int arr[],int index[],int n)
{
    for(int i=0;i<n;i++)
    {
      while(index[i]!=i)
      {
        int old_i = index[index[i]];
        int old_e = arr[index[i]];
        arr[index[i]] = arr[i];
        index[index[i]] = index[i];
        index[i] = old_i;
        arr[i] = old_e;
    }
}
int main()
{
  int arr[] = {50, 40, 70, 60, 90};
  int index[] = {3,  0,  4,  1,  2};
  int n = 5;
  reorder(arr,index,n);
  return 0;
}
