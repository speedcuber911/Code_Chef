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
while(t--)
{
  string a;
  cin>>a;
  int b = 0;
  for(int i=a.length()-1;i>=a.length()/2;i--)
  {
    if(a[b]!=a[i])
      a[i]=a[b];
    b++;
  }
  cout<<a<<endl;
}
return 0;
}
