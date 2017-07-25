#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
int n,q;
int index,key;
string a;
cin>>n>>q;
vector<int>r(n,0);
vector<int>c(n,0);
while(q--)
{
  cin>>a;
  if(a[0]=='R')
    {
      cin>>index;
      cin>>key;
      r[index]+=key;
    }
  if(a[0]=='C')
    {
      cin>>index;
      cin>>key;
      c[index]+=key;
    }
}
long int max=0,max2=0;
for(int i=0;i<n;i++)
  {
    if(max<r[i])
      max=r[i];
    if(max2<c[i])
      max2=c[i];
  }
cout<<max+max2<<endl;
return 0;
}
