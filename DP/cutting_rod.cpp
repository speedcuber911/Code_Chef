#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
int val[8]={1,5,8,9,10,17,17,20};
int mval(int n)
{
  if(n==0 || n==1)
    return 1;
  else
    {
      for(int i=1;i<n;i++)
        {
          return max(val[i-1])
        }
    }
}
int main()
{
  int n;
  cin>>n;
  cout<<mval(n)
  return 0;
}
