#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;


int lc(string a , string b,int n,int m)
{
  if(n==0 || m==0)
    return 0;
  if(a[n]==b[m])
    return 1+lc(a,b,n-1,m-1);
  else
    if(a[n]!=b[m])
          return max(lc(a,b,n,m-1),lc(a,b,n-1,m));
}
int  main()
{
  string a,b;
  int n,m;
  cin>>a>>b;
  n = a.length();
  m = b.length();
  cout<<lc(a,b,n,m)<<endl;
  return 0;
}
