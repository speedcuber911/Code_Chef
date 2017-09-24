#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int maxl(string a)
{
  map<char,int>m;
  int local_l=0,max_l=INT_MIN;
  for(int i=0;i<a.length();i++)
  {
    if(m[a[i]]==0)
    {
      m[a[i]]=1;
      local_l++;
    }
    else
      if(m[a[i]]>0)
    {
      if(max_l<local_l)
        max_l = local_l;
      local_l = 0;
      m.clear();
    }
  }
  return max(local_l,max_l);
}
int main()//Doesnt feel like DP at all
{
  string a;
  cin>>a;
  cout<<maxl(a)<<endl;
  return 0;
}
