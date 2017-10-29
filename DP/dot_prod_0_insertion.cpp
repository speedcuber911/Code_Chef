#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int n,m;
int dp[100][100] = {0};
int _max(int a[],int b[],int i,int j)
{
    if(i >=m || j >= n  || n-j>m-i))
      return 0;
    // cout<<a[i]*b[j]<<endl;
    if(dp[i][j]==0)
      dp[i][j]  = max( (a[i]*b[j] + _max(a,b,i+1,j+1)) , _max(a,b,i+1,j));;
    return dp[i][j];
}
int main()
{
  int a[] = {1,2,3};
  int b[] = {4,1};
  m = 3;
  n = 2;
  cout<<_max(a,b,0,0);
  return 0;
}
