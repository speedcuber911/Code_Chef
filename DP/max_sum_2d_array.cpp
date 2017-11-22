#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>

using namespace std;

int kadane(vector<int>temp,int start,int end)
{
  int local_sum,max_sum=INT_MIN;
  int local_start = 0;
  end = -1;
  for(int i=0;i<temp.size();i++)
  {
    local_sum += temp[i];
    if(local_sum<0)
    {
      local_sum = 0;
      local_start = i+1;
    }
    else
      if(max_sum < local_sum)
    {
      max_sum = local_sum;
      start = local_start;
      finish = i;
    }
  }
  if(finish!=-1)
    return max_sum;

  for(i)
}
int main()
{
  return 0;
  int left,right,i;
  for(left=0;left<col;left++)
  {
    vector<int>temp(row,0);
    for(right=left;right<col;right++)
    {
      for(i=0;i<row;i++)
        temp[i] += M[i][right];

    }
  }
}
