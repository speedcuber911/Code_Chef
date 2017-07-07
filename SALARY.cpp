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
    vector<int>a(n);
    int small= 10001;
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        if(a[i]<small)
          small = a[i];
      }
    long int turns=0;
    for(int i=0;i<n;i++)
    {
      if(a[i]!=small)
        {
          turns += (a[i]-small);
        }
    }
    cout<<turns<<endl;
  }
  return 0;
}
