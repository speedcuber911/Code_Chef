#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<stack>

using namespace std;
bool isatom(char a)
{
  return (a=='O' || a=='H' || a=='C');
}
bool isnum(char a)
{
  return( (int(a)-48)>=0 && (int(a)-48) < 10);
}
int main()
{
  string s;
  cin>>s;
  map<char,int>dict;
  dict['H'] = 1;
  dict['C'] = 12;
  dict['O'] = 16;
  string b;
  for(int i=0;i<s.length();i++)
    {
      b+=s[i];
      if(s[i]==')' && i!=s.length()-1)
        {
          if(!isnum(s[i+1]))
            b+='1';
        }
      // else
    }
  // cout<<b<<endl;
  stack<char>s;
  long long int temp =0;
  for(int i=0;i<b.length()-1;i++)
  {
    if(b[i]=='(')
      s.push(b[i]);
    else
      if(isatom(b[i]))
        temp += dict[b[i]];
    else

  }
  return 0;
}
