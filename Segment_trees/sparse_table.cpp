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
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k = floor(log(n))+1;
  vector<vector<int> >lookup(n,vector<int>(k,0));
  for(int i=0;i<n;i++)
    lookup[i][0] = i;
  for(int j=1;(1<<j)<=n;j++)
      for(int i=0;(i + (1<<j)-1<n);i++ n )
          lookup[i][j] = lookup[i][j-1] + lookup[i + (1 << (j-1))][j-1];

  return 0;
}
