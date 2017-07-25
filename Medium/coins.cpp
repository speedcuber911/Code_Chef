#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

long int split(long int n)
{
  if(n<=2)
    return n;    
  else
    return split(n/2) + split(n/3) + split(n/4);
}
int main()
{
int t;
cin>>t;
while(t--)
{
long int n;
cin>>n;
cout<<split(n);
}
return 0;
}
