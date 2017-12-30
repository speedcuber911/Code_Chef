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


int main()//coin change
{
  int n;
  cin>>n;
  int change;
  cin>>change;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<vector<int> >dp(change+1,vector<int>(n,0));
  for(int i =0;i<change+1;i++)
    for(int j=0;j<n;j++)
    {
      if(i==0)
        dp[i][j] = 1;
      else
      {
      if(i >= arr[j]) //take the coin
        dp[i][j] += dp[i-arr[j]][j];
      else
        dp[i][j] +=0;
      if(j>=1)//dont take the coin
        dp[i][j] += dp[i][j-1];
      else
        dp[i][j] += 0;
      }
    }
    for(int i =0;i<change+1;i++)
      {
        for(int j=0;j<n;j++)
          cout<<dp[i][j]<<"\t";
        cout<<endl;
      }
    cout<<"The answr is "<<dp[change][n-1]<<endl;  


}
