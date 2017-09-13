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
  vector<int> cset(6);
  cset[0]=2;
  cset[1]=2;
  cset[2]=5;
  cset[3]=7;
  cset[4]=8;
  cset[5]=9;
  int n =100;
  cout<<cc(cset,6,n)<<endl;
  return 0;
}
