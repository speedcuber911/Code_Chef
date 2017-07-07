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
  long long int n,k;//no. of candies, student no.
  cin>>n>>k;
  if(n==0 && k==0)
    cout<<0<<" "<<0<<endl;
  else
    if(n!=0 && k==0)
        cout<<0<<" "<<n<<endl;
   cout<<0<<" "<<0<<endl;
  else
    cout<<n/k<<" "<<n%k<<endl;
  }
  return 0;
}
