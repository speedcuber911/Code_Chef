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

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
		return(3);
	else
    if(symbol == '*' || symbol == '/')
		return(2);
	else
    if(symbol == '+' || symbol == '-')          /* lowest precedence */
		return(1);
	else
		return(0);
}

int main()
{
	while(n--)
	{
  string a;
	cin>>a;
  string b;
  stack<char>s;
  for(int i=0;i<a.length();i++)
  {
    if(a[i]=='(')
      s.push(a[i]);
    if(a[i]!= '+' && a[i]!= '*' && a[i]!= '-' && a[i]!= '/' && a[i]!= '^' && a[i]!='(' && a[i]!= ')')
      b = b + a[i];
    if(a[i]== '+' || a[i]== '*' || a[i]== '-' || a[i]== '/' || a[i]== '^')
    {
        char r = a[i];
        while(!s.empty() && s.top()!= '(' && precedence(s.top()) >= precedence(r))
        {
          b = b + s.top();
          s.pop();
        }
      s.push(a[i]);
    }
    if(a[i]==')')
    {
        while(!s.empty())
          {
            if(s.top()=='(')
              {
                s.pop();
                break;
              }
          // cout<<s.top()<<endl;
          b = b + s.top();
          s.pop();
          }
    }
    // cout<<b<<endl;
  }
  cout<<b<<endl;
	}
  return 0;
}

// ABC*DEF^/G*-H*+
// ABC*DEF^/G*-H*+
