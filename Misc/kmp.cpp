#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void cons_lps(vector<int>&v,string b)
{
  v[0]=0;
  int i = 1;
  int len = 0;
  while(i<v.size())
  {
    if(b[len] == b[i])
    {
      len++;
      v[i] = len;
      i++;
    }
    else
    {
      if(len!=0)
      {
          len = v[len-1];
      }
      else
      {
        v[i] = 0;
        i++;
      }
  }
}
}
void kmp(vector<int>&pos,string a,string b)
{
  int n = a.length();
  int m = b.length();
  vector<int>v(m);
  cons_lps(v,b);
  int i=0,j=0;
  // j for substr, i for main string
  while(i<n)
  {
    if(a[i] == b[j])
      {
        i++;
        j++;
      }
    if(j==m)
    {
        pos.push_back(i-j);
        j = v[j-1];
    }
    else
      if(i<n && a[i]!=b[j])
      {
        if(j!=0)
          j = v[j-1];
        else
          i++;
      }

  }
}
int main()
{
  string a,b;
  cin>>a>>b;
  vector<int>pos;
  kmp(pos,a,b);
  for(int i=0;i<pos.size();i++)
    cout<<pos[i];
  return 0;
}
