#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

#define mod 10000009
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
  string a;
  cin>>a;
  bool bi =0;
  long long int ways=1;
  map<char,char> dict;
  for(int i=0;i<(a.length()/2);i++)
  {
      dict[a[i]]=a[a.length()-1-i];
  }
  map<char,char>::iterator it;
  if(a.length()==1)
    {
      if(a[0]=='?')
        ways = ways*26;
    }
  else
  {
    for(it=dict.begin();it!=dict.end();++it)
    {
      if(it->first=='?' && it->second=='?')        
          ways = (ways*26)%mod;
      else
        if(it->first=='?' || it->second=='?')
          { if(bi)
              ways = (ways+1)%mod;
            bi=1;
          }
    }
    if(a.length()%2!=0)
      if(a[a.length()/2]=='?')
        ways-=1;
    }
  cout<<ways<<endl;
}
return 0;
}
