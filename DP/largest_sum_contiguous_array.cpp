#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>a(n);
  vector<int>lis(n);
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
  lis[0] = a[0];
  for(int i=1;i<n;i++)
      lis[i] = max(a[i],lis[i-1]+a[i]);
  int maxer = INT_MIN;
  for(int i=0;i<n;i++)
    maxer = max(maxer,lis[i]);
  cout<<maxer<<endl;
  return 0;
}
