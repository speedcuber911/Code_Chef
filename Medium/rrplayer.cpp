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
  // cout<<setprecision(2);
  // cout<<fixed;
  while(t--)
  {
    int n;
    cin>>n;
    float result = 0.0;
    for(int i=1;i<=n;i++)
    {
      result +=   float(1.0/float(i));
    }
    cout<<result*n<<endl;
  }
}
