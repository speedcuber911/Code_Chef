#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int cc(vector<int>s,int m,int n)
{
  if(n==0)
    return 1;
  if(n<0)
    return 0;
  if(m<=0 && n>=0)
    return 0;
  return cc(s,m-1,n) + cc(s,m,n-s[m-1]);
}
int main()
{
  vector<int> cset(3);
  cset[0]=1;
  cset[1]=2;
  cset[2]=3;
  int n;
  cin>>n;
  cout<<cc(cset,3,n)<<endl;
  return 0;
}
