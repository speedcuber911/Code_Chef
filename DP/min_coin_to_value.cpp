#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int _make_change(int change,vector<int>coins)// DO this today!
{
  vector<int>dp(change+1,INT_MAX);
  dp[0] =0;
  for(int i=1;i<=change;i++)
      for(int j=0;j<coins.size();j++)
      {
      if(coins[j]<=i)
        {
          int s = dp[i-coins[j]];
          if(s+1 < dp[i] )
            dp[i] = s+1;
        }
    }
    return dp[change];
}
int main()
{
  int change;
  int n;
  cin>>n;
  vector<int>coins(n);
  for(int i=0;i<n;i++)
    cin>>coins[i];
  cout<<_make_change(change,coins);
  return 0;
}
