#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  int big=0;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]>big)
        big=a[i];
    }
  int i;
  for(i=0;i<n;i++)
  {
     m = (m - (big-a[i]));
  }
  if(m==0 || m%n==0)
    cout<<"Yes\n";
  else
    cout<<"No\n";
}
return 0;
}
