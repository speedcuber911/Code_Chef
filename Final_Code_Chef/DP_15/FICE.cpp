#include <cstdio>
#include <vector>
#include<iostream>
#include<math.h>
#include<map>
#include<queue>

using namespace std;

int solver(int n,int m)
{
  if(n==0)
    return 1;
  // if(n==1)
    // return 2;
  if(n%2==0)
    return 2 + solver(n-1);
  if(n%2!=0)
    return 2 + 
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    cout<<solver(n,m);
  }
  return 0;
}
