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
int n,k;
while(t--)
{
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a.begin(),a.end());
}
return 0;
}
