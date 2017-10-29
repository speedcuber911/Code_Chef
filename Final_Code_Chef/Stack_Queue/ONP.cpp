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

int pre(char a)
{
  if(a=='^')
    return 3;
  if(a== '/' || a== '*')
    return 2;
  if(a== '+' || a== '-')
    return 1;
  return 0;
}
int main()
{
  stack<char>st;
  string a;
  cin>>a;
  string expr;
  for(int i=0;i<a.length();i++)
  {
    if(a[i]=='(')
      st.push(a[i]);
    if(a[i]>=97 && a[i]<=123)
      expr += a[i];
    if(a[i]=='+' || a[i] == '*' || a[i] == '/' || a[i] == '-' || a[i] == '^' )
      {
        while(!st.empty() && pre(a[i]) < pre(st.top()) && st.top()!= '(')
          {
              expr += st.top();
              cout<<"Popping "<<st.top()<<endl;
              st.pop();
          }
        st.push(a[i]);
      }
    if(a[i]==')')
      {
        while(!st.empty() && st.top() != ')')
            {
              if(st.top()!= '(')
                expr += st.top();
              st.pop();
            }
        // if(!st.empty())
          // st.pop();
      }
    cout<<expr<<endl;
  }
  cout<<expr<<endl;
  return 0;
}
