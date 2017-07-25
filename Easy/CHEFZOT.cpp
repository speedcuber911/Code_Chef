#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
int n;
cin>>n;
int a,temp=0,count=0;
for(int i=0;i<n ;i++)
{
  cin>>a;
  if(a!=0)
  {
    temp++;
  }
  else
   if(a==0)
    {
      if(temp>count)
      count=temp;
        temp=0;
    }
  // cout<<temp<<" " ;
}
cout<<max(temp,count)<<endl;
return 0;
}
