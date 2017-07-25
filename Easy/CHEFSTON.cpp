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
  long int t,k;
  cin>>t;
  while(t--)
  {
    long int n,k;
    cin>>n>>k;
    vector< vector<long int> > a(n,vector<long int>(2));
    for(int i=0;i<n;i++)
      {
      cin>>a[i][0];
      a[i][0] = (k/a[i][0]);
      }

    for(int i=0;i<n;i++)
        cin>>a[i][1];
    // sort(a.begin(), a.end(),sortcol);
    long int g = (a[0][0]*a[0][1]);
    for(int i=0;i<n;i++)
    {
      if((a[i][0]*a[i][1])>g)
        g=(a[i][0]*a[i][1]);
    }
    cout<<g<<endl;
  }
}
