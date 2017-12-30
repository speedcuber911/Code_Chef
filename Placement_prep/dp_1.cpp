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

int main()//fibo
{
int n;
cin>>n;
vector<int>dp(n+1,1);
dp[1] = 1;
for(int i=2;i<dp.size();i++)
  dp[i] = (dp[i-1] + dp[i-2]);
for(int i=0;i<dp.size();i++)
  cout<<dp[i]<<"\t";
return 0;
}
