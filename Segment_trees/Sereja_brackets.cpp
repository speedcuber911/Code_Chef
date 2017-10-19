#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void build(int i,int l,int r)
{
    if(r-l<2)
      {
        if(s[l] =='(')
        o[i] = 1;
      else
        c[i] = 1;
      return 0;
      }
    int mid = (l+r)/2;
    build(2*i+1,l,mid);
    build(2*i+1,mid+1,r);
    int t = min()

}
int main()
{
  build(0,0,n);
  return 0;
}
