#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
int main()
{

  int n,k;
    cin>>n>>k;
    vector<long int>a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
      long int max= -2000000001,min=2000000001;
      for(int i=0;i<a.size();i++)
        {
          if(a[i]>max)
            max=a[i];
          if(a[i]<min)
            min=a[i];
        }
    if(k==0)
    {
      for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    }
    else
      if(k%2==0)
      {
        for(int i=0;i<n;i++)
          cout<<a[i]-min<<" ";
      }
    else
        for(int i=0;i<n;i++)
          cout<<max-a[i]<<" ";
    cout<<endl;      
return 0;
}
