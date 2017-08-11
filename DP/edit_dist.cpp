#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;



int mine(string a,string b,int m,int n)
{
  if(m<0)
    return max(0,n);
  if(n<0)
    return max(0,m);
  else
    if(a[m]==b[n])
      return mine(a,b,m-1,n-1);
  else
    if(a[m]!=b[n])
    {
      return 1 + min(mine(a,b,m-1,n-1),min(mine(a,b,m,n-1),mine(a,b,m-1,n)));
    }
}
int main()
{
  string a,b;
  cin>>a>>b;
  cout<<mine(a,b,a.length()-1,b.length()-1)<<endl;
  return 0;
}
