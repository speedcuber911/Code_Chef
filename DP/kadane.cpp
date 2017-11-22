#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int local_sum,max_sum = INT_MIN;
  int start,end;
  for(int i=0;i<n;i++)
  {
    local_sum += arr[i];
    if(local_sum<0)
      {
        local_sum = 0;
        local_start = i+1;
      }
    else
        if(local_sum > max_sum)
          {
            max_sum = local_sum;
            start = local_start;
            finish = i;
          }
  }
  return 0;
}
