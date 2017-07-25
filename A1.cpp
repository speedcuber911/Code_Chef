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
  int n,m,val;
  cin>>n>>m;
  vector<int>a;

  for(int i=0;i<n;i++)
    {
      cin>>val;
      if(val<=m)
        a.push_back(val);
    }
  sort(a.begin(),a.end());
  for(int i=a.size()-1;i>=0;i--)
  {
    if(m>=a[i])
      m-=a[i];
  }
  if(m==0)
    cout<<"Yes\n";
  else
    cout<<"No\n";
}
return 0;
}
