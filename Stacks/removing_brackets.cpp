#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;

int main()
{
  string s;
  cin>>s;
  stack<char>st;
  // st.push('+');
  for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]!=')')
          st.push(s[i]);
        else
          {
            string expr;
            while(!st.empty() && st.top()!= '(')
              {
                expr += (st.top());
                st.pop();
              }
              cout<<expr<<endl;
          }
    }
  return 0;
}
