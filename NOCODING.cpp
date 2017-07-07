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
  long int inst=0;
  string a;
  cin>>a;
  inst+=a.length()+1;
  for(int i=0;i<a.length()-1;i++)
  {
    if(a[i]>a[i+1])
      inst+= 26- int(a[i]-a[i+1]);
    else
        inst+= a[i+1]-a[i];
  }
  if(inst<=11*a.length())
    cout<<"YES\n";
  else
    cout<<"NO\n";
}
return 0;
}
