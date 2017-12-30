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


int main()//0-1 knapsac
{
  int wt;
  cin>>wt;
  int weights[] = {1,3,4,5};
  int vals[] = {1,4,5,7};
  vector<vector<int> >dp(wt+1,vector<int>(4,0));
  for(int i=0;i<4;i++)
    for(int j=0;j<(wt+1);j++)
      {
        if(weights[i]<j)//take the weight
          dp[i][j] = dp[i-1][j];
        else
          dp[][]
        if(weights[i])//dont take the weight
      }
  return 0;
}
