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


int main()//matrix chain multiplication
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
      cin>>arr[i];
    vector<vector<int> >dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
      dp[i][i] = 0;
    int q;
    
    for(int l=2;l<n;l++)
      {
        for(int i=0;i<arr.size()-l;i++)
          {
            int j = i+l;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++)
            {
              q = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
              dp[i][j] = min(dp[i][j],q);
          }
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cout<<dp[i][j]<<"\t";
      cout<<endl;
    }

}
