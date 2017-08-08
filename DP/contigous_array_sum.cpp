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
  vector<int>a(n);
  for(int i=0;i<a.size();i++)
      cin>>a[i];
  int r=a[0],s=a[0];
  for(int i=i;i<a.size();i++)
  {
    r = max(a[i],r+a[i]);
    s = max(r,s);
  }
  cout<<s<<endl;
}
