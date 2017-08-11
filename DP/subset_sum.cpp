#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool det(int set[],int sum,int n)
{
  if(sum==0)
    return 1;
  if(n==0 && sum!=0)
    return 0;
  if(sum-set[n-1]<0)
    return det(set,sum,n-1);
  return det(set,sum-set[n-1],n-1) || det(set,sum,n-1);
}
int main()
{
  int set[6] = {3, 34, 4, 12, 5, 2};
  int sum;
  cin>>sum;
  cout<<det(set,sum,6)<<endl;
  return 0;
}
