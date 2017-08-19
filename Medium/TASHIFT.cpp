#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  string a,b,c;
  cin>>a>>b;
  size_t found,found2;
  int i;
  for(i=a.length()-1;i>=0;i--)
  {
    c = a.substr(0,i+1);
    found = b.find(c);
    if(found!=string::npos)
      {
      while(found!=string::npos)
      {
        found2 = found;
        found = b.find(c,found+1);
      }
      break;
      }
    else
      continue;
  }
  cout<<found2<<endl;
  return 0;
}
