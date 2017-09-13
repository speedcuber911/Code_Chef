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
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int i,j,s=0;
    while(n--)
    {
        cin>>i>>j;
        s+= (i-j);
    }
  cout<<s<<endl;
}
  return 0;
}
