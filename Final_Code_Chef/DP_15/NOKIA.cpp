#include <cstdio>
#include <vector>
#include<iostream>
#include<math.h>
#include<map>
#include<queue>

using namespace std;

int wired(int n,int m,int p)
{
  if(p==n)
    return m;
  if(p==n && m<=0)
    return 0;
  else
    return
    (n+1) +  wired(n,m-(n+1)-p,p+1);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    cout<<wired(n,m,0);
  }
  return 0;
}
