#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int solve(int n,int k)
{
  vector<int>dp(n+1,0);
  dp[1] = k;
  int same = 0, diff = k;
  for(int i =2;i<=n;i++)
  {
    same = diff;// same of i is diff i-1
    diff = (dp[i-1] + dp[i-2]);
    dp[i] = (same + diff);
  }
  return dp[n];
}
int main()
{
  int n,k;
  cin>>n>>k;
  // t(n) = (k-1)t(n-1)  = (k-1)*(s(n-1) + d(n-1));
  cout<<solve(n,k);
  return 0;
}
