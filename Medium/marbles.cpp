#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>

using namespace std;

int ar[1000000][1000000];
int bion(int n,int r)
{
  if(r==0 || r==n)
      return 1;
  if(r==1 || n-r==1)
      return n;
  else
    {
      if(ar[n-1][r-1]!=0)

    }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    cout<<bion(n-1,n-k)<<endl;
  }
  return 0;
}
