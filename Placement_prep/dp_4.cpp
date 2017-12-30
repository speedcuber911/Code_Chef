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

int _lcs(string a,string b)
{
  vector<vector<int> >dp(a.size()+1,vector<int>(b.size()+1,0));
  for(int i=1;i<=a.size();i++)
    for(int j=1;j<=b.size();j++)
    {
        if(a[i-1]==b[j-1])
          dp[i][j] = 1 + dp[i-1][j-1];
        else
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
    for(int i=0;i<=a.size();i++)
      {
        for(int j=0;j<=b.size();j++)
          cout<<dp[i][j]<<"\t";
        cout<<endl;
      }
    cout<<endl;
  return dp[a.size()][b.size()];
}
int main()//Longest common subsequence
{
  string a,b;
  cin>>a>>b;
  cout<<_lcs(a,b)<<endl;
  return 0;
}
