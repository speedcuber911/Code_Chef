#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int min_inserts(string s,string r)
{
  int len = s.length();
  vector<vector<int> >l(len,vector<int>(len,0));
  for(int i=1;i<=len;i++)
    for(itn j=1;j<=len;j++)
    {
      if(s[i-1]==r[j-1])
        l[i][j] = l[i-1][j-1] + 1;
      else
        l[i][j] = max(l[i-1][j],l[i][j-1]);
    }
    return l[len][len];
}
int main()
{
  string s;
  cin>>s;
  r  = reverse(s.begin(),s.end());
  cout<<s.length()-min_inserts(s);
  return 0;
}
