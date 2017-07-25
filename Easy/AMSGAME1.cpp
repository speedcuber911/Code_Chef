#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;


int gcd(int a,int b)
{
  int temp;
  while(b!=0)
  {
    temp = a%b;
    a = b;
    b = temp;
  }
  return a;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
      }
    if(n==1)
      cout<<a[0]<<endl;
    else{
      int ans = gcd(a[0],a[1]);
    for(int i=2;i<n;i++)2
    {
        if(ans!=1)
          ans = gcd(ans,a[i]);
        else
            break;
    }
    cout<<ans<<endl;
  }
}

return 0;
}
