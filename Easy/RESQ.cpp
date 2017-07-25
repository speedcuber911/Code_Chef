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
    int sq = sqrt(n);
    int i,j;
    for(i=sq;i>=1;i--)
    {
      if(n%i==0)
        {
          j=n/i;
          cout<<abs(j-i)<<endl;
          break;
        }
    }
  }
}
