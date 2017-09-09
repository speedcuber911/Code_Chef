#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<queue>

using namespace std;

void all_perms(char arr[],vector<string>r)
{
  for(int i=0;i<r.size();i++)
  {
      if(r[i].length()!=4)
        for(int u=r[i].length();u<4;u++)
          {
            string temp = "0" + r[i];
            r[i] = temp;
          }
          cout<<r[i]<<" : ";
      for(int j=0;j<4;j++)
      {
        if(r[i][j]=='1')
          cout<<arr[j];
      }
      cout<<endl;
  }
}
int main()
{
  int n;
  char arr[4] = {'a','b','c','d'};
  n = 15;
  vector<string>v_s;
  queue<string>q;
  q.push("1");
  while(n--)
  {
    string s = q.front();
    q.pop();
    v_s.push_back(s);
    string s2 = s;
    q.push(s.append("0"));
    q.push(s2.append("1"));
  }
  all_perms(arr,v_s);
  return 0;
}
