#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int cstate(vector<int>a,int s,int e)
{
  int count=0;
  for(int i=(s+e)/2;i<=e;i++)
    {
      if(a[i]==1)
        count++;
      if(a[i-(s+e)/2]==1)
        count++;
    }
  return count;
}
void perf(vector<int>&a,int s,int e)
{
  for(int i=(s+e)/2;i<=e;i++)
    {
      if(a[i]==1)
        a[i]=0;
      else
        a[i]=1;
      if(a[i-(s+e)/2]==1)
        a[i]=0;
      else
        a[i]=1;
    }
}
int main()
{
  int n,q;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>q;
  vector<int>a(n,0);
  int x,y,z;
  for(int i=0;i<q;i++)
  {
    cin>>x>>y>>z;
    if(x==0)
      perf(a,y,z);
    else
      cout<<cstate(a,y,z)<<endl;
  }
  return 0;
}
