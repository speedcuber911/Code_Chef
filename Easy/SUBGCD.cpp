#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int gcd(int a,int b)
{
  while(a!=0 && b!=0)
  {
    if(a>b)
      a = a%b;
    else
      b = b%a;
  }
  return a;
}
int main()
{
int t;
cin>>t;
while(t--)
{
  int n;
  cin>>n;
  long int count=0;
  long int temp=0;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<n-1;i++)
  {
    if(gcd(a[i],a[i+1])==1)
      {
        temp++;
      }
    else
      {
        temp=0;
      }
      if(temp>count)
        count = temp;
  }
  if(count==0)
    cout<<-1<<endl;
  else
    cout<<count+1<<endl;
}
return 0;
}
