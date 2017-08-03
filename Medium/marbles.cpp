#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>

using namespace std;
long long bion(int n,int r)
{
  int  i=0;
  long long result=1;
  if (r > n/2)
  {
    r = n - r;
  }
  for (i = 0; i < r; i++)
  {
    result *= (n-i);
    result /= (i+1);
  }
  return result;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
      cout<<bion(n-1,n-k)<<endl;
  }
  return 0;
}
