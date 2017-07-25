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
  int n;
  cin>>n;
  int cost=0;
  vector<int>a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a.begin(),a.end());  
  for(int i=n-1;i>=0;)
  {
    cost+=a[i];
      i--;
    if(i>=0)
    {
      cost+=a[i];
      i-=3;
    }
  }
  cout<<cost<<endl;
}
  return 0;
}
