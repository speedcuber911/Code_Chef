#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

vector<int>a(100,0);
int fib(int n)
{
  if(n==0 || n==1)
    return n;
  if(a[n]!=0)
    return a[n];
  else{
    a[n] = fib(n-1) + fib(n-2);
    return a[n];
  }
}
int main()
{
  int n;

  cin>>n;
  for(int i=0;i<10;i++)
    cout<<fib(i)<<" ";
  return 0;
}
