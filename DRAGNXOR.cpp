#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

long int load(long int u)
{
  long int count=0;
  while(u!=0)
  {
    if(u%2==1)
      count++;
    u=u/2;
  }
  return count;
}
 int main()
{
  long int t;
  cin>>t;
  while(t--)
  {
    long int n;
    cin>>n;
    long int add=0;
    long int e,f;
    cin>>e>>f;
    e = load(e);
    f = load(f);
    if((e+f)<=n)
    {
      e = e+f;//no. of ones in the expression
      while(e!=0)
      {
        add += pow(2,n-1);
        e--;
        n--;
      }
    cout<<add<<endl;
    }
  else
  {
    long int d= abs(n+n - (e+f));
    while(d!=0)
    {
      add += pow(2,d);
      d--;
    }
    cout<<add<<endl;
  }
  }
  return 0;
}
