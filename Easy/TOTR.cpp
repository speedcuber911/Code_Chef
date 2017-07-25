#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<ctype.h>

using namespace std;

int main()
{
int t;
cin>>t;
string m;
cin>>m;
map<char,char> trans;
for(int i=0;i<26;i++)
{
      trans[char(97+i)] = m[i];
}
while(t--)
{
  string u;
  cin>>u;
  for(int i=0;i<u.length();i++)
  {
      char r = u[i];
      if(islower(r))
        {
          map<char,char>::iterator it = trans.find(r);
          if(it!=trans.end())
            {
              cout<<trans[r];
            }
        }
      else
        if(isupper(r))
      {
        r = char(tolower(r));
        map<char,char>::iterator it = trans.find(r);
        if(it!=trans.end())
          {
            cout<<char(toupper(trans[r]));
          }
      }
      else
        if(r=='_')
          cout<<" ";
      else
      {
        cout<<r;
      }
  }
  cout<<endl;
}
return 0;
}
