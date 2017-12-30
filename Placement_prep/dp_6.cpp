#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>
#include<queue>

using namespace std;


int main()//min cost path
{
  int n;
  cin>>n;
  vector<vector<int> >arr(n,vector<int>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  vector<vector<int> >dp(n,vector<int>(n));
  dp[0][0] = arr[0][0];
  for(int i=1;i<n;i++)
    dp[0][i] = arr[0][i] + dp[0][i-1];
  for(int i=1;i<n;i++)
    dp[i][0] = arr[i][0] + dp[i-1][0];
  for(int i=1;i<n;i++)
    for(int j=1;j<n;j++)
      dp[i][j] = arr[i][j] + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
  // for(int i=0;i<n;i++)
  //   {
  //     for(int j=0;j<n;j++)
  //       cout<<dp[i][j]<<"\t";
  //     cout<<endl;
  //   }
  cout<<dp[n-1][n-1]<<endl;
}
