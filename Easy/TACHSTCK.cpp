#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
long int n,d;
cin>>n>>d;
vector<long int> a(n);
for(long int i=0;i<n;i++)
  cin>>a[i];
sort(a.begin(),a.end());
long int count=0;
for(long int i=0;i<n;i++)
{
    if((i+1)<n)
    if((a[i+1]-a[i])<=d)
      {
      count++;
      i++;
      }
}
cout<<count;
return 0;
}
