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
  int t,k;
  cin>>t;
  int a,b;
  while(t--)
  {
    a = 103993;
    b = 33102;
    a = a%b;
    cin>>k;
    vector<int>rem;
    if(k==0)
      cout<<"3\n";
    else
    {
      for(int i=0;i<k;i++)
      {
        a *= 10;
        rem.push_back(a/b);
        a = a%b;
      }
      cout<<"3.";
      for(int i=0;i<rem.size();i++)
      cout<<rem[i];
      cout<<endl;
    }
  }
}
