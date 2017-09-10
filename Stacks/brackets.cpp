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

bool opener(char exp)
{
  if(exp=='(' || exp=='{' || exp == '[')
    return 1;
  else
    return 0;
}
int main()
{
  map<char,char> complement;
  complement['('] = ')';
  complement['{'] = '}';
  complement['['] = ']';
  string exp  = "[(])";
  stack<char>s;
  for(int i=0;i<exp.length();i++)
  {
      if(opener(exp[i]))
        s.push(exp[i]);
      else
        {
          if(complement[s.top()]==exp[i])
            s.pop();
          else
            {
              cout<<"Unbalanced\n";
              exit(0);
            }
        }
  }
  cout<<"Balanced\n";
}
