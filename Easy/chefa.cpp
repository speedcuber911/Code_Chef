#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
int t,n;
cin>>t;
while(t--)
{
  cin>>n;
  long long int sum=0;
  vector<long int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=n-1;i>=0;i-=2)
    sum+=a[i];
  cout<<sum<<endl;
}
return 0;
}
