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
  int n;
  cin>>n;
  string a,b,c;
  bool flip = 0;
  cin>>a>>b;
  c = b+b;
  vector<int>pos;
  int maxi;
  for(int i=a.length();i>0;i--)
    {
      maxi = 1000000000;
      kmp(pos,c,(a.substr(0,i)));
      if(!pos.empty())
      {
        cout<<a.substr(0,i);
        for(int j=0;j<pos.size();j++)
        {
          if(pos[j]<maxi)
            {
              maxi = pos[j];
              flip=1;
            }
        }
        break;
      }
      pos.clear();
    }
    if(flip)
      cout<<maxi;
  return 0;
}
