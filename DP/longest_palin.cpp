#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

string s;
int r[50][50]={0};
int lps(int beg,int end)
{
  if(beg==end)
    return 1;
  if(end-beg==1)
  {
    if(s[beg]==s[end])
      return 2;
    else
      return 0;
  }
  if(s[end] == s[beg])
    {
        return 2 + lps(beg+1,end-1);
    }
  else
  {
    if(r[beg][end]==0)
      r[beg][end] =  max(lps(beg,end-1),lps(beg+1,end));
    else
      return r[beg][end];
  }
}
int main()
{
  cin>>s;
  int beg=0,end=s.length()-1;
  cout<<lps(beg,end);
  return 0;
}
