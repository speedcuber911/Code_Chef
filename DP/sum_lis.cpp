#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
int main()
{

  int arr[7] = {1, 101, 2, 3, 100, 4, 5};
  int n=7;
  int tot_sum  = 0;
  int lis[7];
  for(int i=0;i<7;i++)
    lis[i]=arr[i];
  for(int i=1;i<7;i++)
    for(int j=0;j<i;j++)
      {
        if(arr[i]>arr[j]  && lis[i]<arr[i]+lis[j])
            lis[i] = lis[j] +arr[i];
      }
for(int i=0;i<n;i++)
  if(tot_sum<lis[i])
    tot_sum = lis[i];
cout<<tot_sum<<endl;
  return 0;
}
