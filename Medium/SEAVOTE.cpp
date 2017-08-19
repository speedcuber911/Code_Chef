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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int temp;
    int sum=0;
    int max = 100+n-1;
    for(int i=0;i<n;i++)
      {
      cin>>temp;
      if(temp!=0)
        sum+=temp;
      if(temp==0)
        max--;
      }
    if(sum>=100 && (sum-max)<=0)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
