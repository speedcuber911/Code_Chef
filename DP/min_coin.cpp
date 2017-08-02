#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int coins[3] = {1,2,3};
bool check(int amount)
{
  for(int i=0;i<3;i++)
    if(amount == coins[i])
      return 1;
  return 0;
}
int minc(int amount)
{
  if(amount == 0)
    return 0;
  if(check(amount))
    return 1;
  else
      return 1 + min(minc(amount-coins[0]),min(minc(amount-coins[1]),minc(amount-coins[2])));
}
int main()
{
  int amount;
  cin>>amount;
  cout<<minc(amount);
  return 0;
}
