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

int  main()
{
  int i=0;
  for(;;)
  {
    i++;
    int ans =0;
    string a;
    cin>>a;
    if(a[0]=='-')
      break;
    stack<char>  st;
    for(int i=0;i<a.length();i++)
    {
      if(a[i]=='{')
        st.push('{');
      if(a[i]=='}' && !st.empty() && st.top() == '{')
        st.pop();
      if(a[i]=='}' && (st.empty() || st.top() == '}'))
        st.push('}');
    }
    if(st.empty())
      cout<<i<<". 0\n";
    else
      {
        vector<char>st2;
        while(!st.empty())
        {
          st2.push_back(st.top());
          st.pop();
        }
        reverse(st2.begin(),st2.end());
        for(char ch : st2)
        {

        }
      }
      cout<<ans<<endl;
  }
  return 0;
}
