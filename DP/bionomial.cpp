#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int a[10][10] ={0};
int bion(int n,int k)
{
  if(k==0 || k==n)
    return 1;
  if(k==1 || k==n-1)
    return n;
  if(a[n][k]!=0)
    return a[n][k];
  else
  {
    a[n][k] = bion(n-1,k-1)  + bion(n-1,k);
    return a[n][k];
  }
}
int main()
{
  int n,k;
  cin>>n>>k;
  cout<<bion(5,2)<<endl;
  cout<<bion(4,2)<<endl;
  cout<<bion(6,3)<<endl;
  return 0;
}
