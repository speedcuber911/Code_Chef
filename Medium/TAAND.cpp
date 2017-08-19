#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  // vector< vector <int > > a(n,vector<int>(30,0));
  vector<int>a(30,0);
  int temp,pos=0;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    pos=0;
    while(temp!=0)
    {
      if((temp&1) == 1)
        a[pos]++;
        pos++;
        temp >>= 1;
    }
  }
for(int i=0;i<30;i++)
  cout<<a[i]<<" ";
  return 0;
}
