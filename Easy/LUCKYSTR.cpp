#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool check(string b, vector<string>a,int k)
{
    size_t found;
    int i;
    bool t = 0;
    for(i=0;i<k;i++)
    {
        found = b.find(a[i]);
        if(found!=string::npos)
        {
          t=1;
          break;
        }
    }
    return t;    
}
int main()
{
int k,n;
cin>>k>>n;
vector<string>a(k);
vector<string>b(n);
for(int i=0;i<k;i++)
  cin>>a[i];
for(int i=0;i<n;i++)
  cin>>b[i];
for(int i=0;i<n;i++)
{
  if(b[i].length()>=47 || check(b[i],a,k))
    cout<<"Good\n";
  else
    cout<<"Bad\n";
}
return 0;
}
