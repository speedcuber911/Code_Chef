#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int max_f(vector<int>a,int n)
{
  if(n==0)
    return a[0];
  else
    return max(a[n],max_f(a,n-1));
}
int main()
{
  vector<int>a(10);
  for(int i=0;i<10;i++)
    a[i] = i;
  cout<<max_f(a,9);
  return 0;
}
