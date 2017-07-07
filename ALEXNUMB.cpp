#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
    {
      long long int n;
      cin>>n;
      vector<long int> a(n);
      for(int i=0;i<n;i++)
        cin>>a[i];
      cout<<(n*(n-1))/2<<endl;
    }
  return 0;
}
