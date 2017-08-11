#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int maxl(vector<int>a,int i)
{
  if(i<0)
    return 0;
  if(a[i-1]<a[i])
    return 1 +  maxl(a,i-1);
  else
    if(a[i-1]>a[i])
      return maxl(a,i-1);

  }
int main()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<maxl(a,a.size()-1)<<endl;
  return 0;
}
