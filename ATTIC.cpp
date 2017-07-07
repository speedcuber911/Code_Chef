#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
  string a;
  cin>>a;
  vector<int>gap;
  int count;
  for(int i=0;i<a.length();i++)
  {
    if(a[i]=='.')
      {   count=0;
          while(a[i]!='#')
        {
          count++;
          i++;
        }
        gap.push_back(count);
    }
  }
  count=0;
  int wav = -1;
  for(int i=0;i<gap.size();i++)
    {
      if(gap[i]>wav)
        {
          count++;
          wav = gap[i];
        }
      else
        count+=0;
    }
    cout<<count<<endl;
}
return 0;
}
