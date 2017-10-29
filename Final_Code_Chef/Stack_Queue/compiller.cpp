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

int main()
{
int t;
cin>>t;
string s;
while(t--)
{
stack<char>st;
cin>>s;
int max = 0;
int sec = 0;
for(int i=0;i<s.length();i++)
{
	if(s[i]== '<')
		{
      st.push('<');
      sec++;
    }
	else
		{
      if(!st.empty())
        st.pop();
      sec--;
    }
	if(st.empty() && i!=0 && sec >=0)
	{
		if(i+1 >max)
			max = i+1;
	}
}
cout<<max<<endl;
}
return 0;
}
