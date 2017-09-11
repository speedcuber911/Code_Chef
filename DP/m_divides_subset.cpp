#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void ss(int a[],int n)
{
    if(n<0)
      return;
    f(n==0)
      cout<< a[0];
    cout<<ss(a,n-1)<<" "<<ss(a,n)<<" ";
}
int main()
{
  int a[4]={3,1,7,5};
  int n;
  cin>>n;
  ss(a,n);
  return 0;
}
