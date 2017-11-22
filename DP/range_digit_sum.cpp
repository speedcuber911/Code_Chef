#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;

int digitize(vector<int> &digit,int x);
{
    while (x)
    {
        digit.push_back(x%10);
        x /= 10;
    }
}

long int digit_sum(int idx,int sum,int tight,vector<int> &digit)
{
  if(idx==-1)
      return sum;
  if(dp[idx][sum][tight] != -1 && tight!=1)
    return dp[idx][sum][tight];
  long long ret = 0;
  int k = (tight)?digit[idx]:9;
  for(int i=0;i<=k;i++)
    {
      int new_tight =  (digit[idx]==i)?tight:0;
      ret += digit_sum(idx-1,sum+i,new_tight,digit);
    }
  if(!tight)
      dp[idx][sum][tight] = ret;
  return ret;
}
int range_digit_sum(int a ,int b)
{
  vector<int>digit_a;
  digitize(digit_a,a);
  vector<int>digit_b;
  digitize(digit_b,b);
  long ans_1 = digit_sum(digit_a.size()-1,0,1,digit_a);
  long ans_2 = digit_sum(digit_b.size()-1,0,1,digit_b);
  return ans_2 - ans_1;
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<range_digit_sum(a,b)<<endl;
  return 0;
}
