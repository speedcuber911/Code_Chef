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

bool pair_sum(int a[],int sum,int n)
{
  int beg=0,end= n-1;
  while(beg<end)
  {
    if((a[end]+a[beg]) < sum)
      beg++;
    else
      if((a[end]+a[beg]) > sum)
        end--;
    else
    {
      // cout<<"Sum found\n"<<a[beg]<<"  "<<a[end]<<endl;
      return true;
    }
  }
  return false;
}
bool triplet_sum(int a[],int sum,int n)
{
  int r,l;
  sort(a,a+n);
  for(int i=0;i<n-2;i++)
  {
    l = i+1;
    r = n-1;
    while(l<r)
    {
      if( (a[i] + a[l] + a[r]) > sum)
        r--;
      else
        if( (a[i] + a[l] + a[r]) < sum)
          l++;
      else
        return true;
    }
  }
  return false;
}
int main()// Basically, do the pair sum method, with a
{
  int a[] = {1, 4, 45, 6, 10, 8};
  int sum = 22;
  int n = 6;
  if(triplet_sum(a,sum,n))
    cout<<"Yipeee!!"<<endl;
  return 0;
}
