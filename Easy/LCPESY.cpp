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
int t;
cin>>t;
string a,b;
while(t--)
{
  cin>>a>>b;
  int arr[125]={0};
  int brr[125]={0};
  for(int i=0;i<a.length();i++)
      arr[int(a[i])]++;
  for(int i=0;i<b.length();i++)
      brr[int(b[i])]++;
  long int count =0;
  for(int i=0;i<125;i++)
    count += (min(brr[i],arr[i]));
  cout<<count<<endl;  
}
return 0;
}
