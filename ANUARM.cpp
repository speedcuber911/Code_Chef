#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int max_val(int val,int n)
{
  return max(n-val,val-0);
}
int main()
{
int t;
cin>>t;
while(t--)
{
  int n,m;
  cin>>n;
  cin>>m;
  int val;
  vector<int>pos(n);
  for(int i=0;i<m;i++)
  {
    cin>>val;
    pos[max_val(val,n)-1] = max_val(val,n);
  }
  for(int i=0;i<n;i++)
    cout<<pos[i]<<" ";
}
}
