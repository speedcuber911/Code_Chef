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

int main()//Longest increasing subsequence
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<int>dp(n,1);
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
      if(arr[i]>arr[j])
        if(dp[i] < dp[j]+1)
          dp[i] = dp[j] + 1;
  // for(int i=0;i<n;i++)
    // cout<<dp[i]<<"\t";
  cout<<"This is the answer-----> "<<dp[n-1]<<endl;
}
