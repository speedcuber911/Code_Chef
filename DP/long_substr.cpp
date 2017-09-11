#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int long_subs(string a,string b,int n,int m)
{
  if(a[n]==b[m])
    return 1 + long_subs(a,b,n-1,m-1);
  if(a[n]!=b[m])
    return 1 + long_subs(a,b,n-1,m);

}

int main()
{
  string a,b;
  cin>>a>>b;
  cout<<long_subs(a,b,a.length(),b.length());

  return 0;
}
