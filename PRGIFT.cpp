#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

#define mod 10000009
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
int n,k;
cin>>n>>k;
int count=0;
vector<int>a(n);
for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]%2==0)
      {
        count++;
      }
    // cout<<a[i];
  }
  if((k==0)&&(count==n))
    count=-1;
  if(count>=k)
    cout<<"YES\n";
  else
    cout<<"NO\n";
}
return 0;
}
