#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{

  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
      }
    sort(a.begin(),a.end());
    int sum=0,sum2=0;
    for(int i=0;i<n;i++)
      if(i<k)
        sum+=a[i];
      else if(i>=k)
        sum2+=a[i];
      int tum=0,tum2=0;
      for(int i=0;i<n;i++)
        if(i<n-k)
          tum+=a[i];
        else if(i>=n-k)
          tum2+=a[i];
      cout<<max(abs(sum-sum2),abs(tum2-tum))<<"\n";
  }
}
