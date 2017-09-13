#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int bion[50][50] = {0};
int cat(int n,int k)
{
  if(k==0 || k==n)
    return 1;
  if(k==1 || k==(n-1))
    return n;
  if(bion[n][k]!=0)
    return bion[n][k];
  else
    {
      bion[n][k]  = cat(n-1,k-1) + cat(n-1,k);
      return bion[n][k];
    }
}
int main()
{
  int n;
  cin>>n;
  if(n==0)
    return 1;
  else
    cout<<cat(2*n,n)/(n+1);

  return 0;
}
