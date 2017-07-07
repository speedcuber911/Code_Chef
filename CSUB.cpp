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
  int n;
  cin>>n;
  string a;
  cin>>a;
  int count=0;
  for(int i=0;i<a.length();i++)
    if(a[i]=='1')
      count++;
  if(count==1)
    cout<<1<<endl;
  else
    {
      count--;
      long long int sum = (float(count)/2)*float(3+count);
      sum+=1;
      cout<<sum<<endl;
    }
}
return 0;
}
