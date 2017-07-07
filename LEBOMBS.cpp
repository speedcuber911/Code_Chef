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
  int dict[1001]={0};
  while(t--)
  {
    int n,count=0;
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<n;i++)
    {
      if(a[i]=='1')
      {
        if(i==0)
          {
              dict[1]=1;
              dict[0]=1;
          }
        if(i==n-1)
        {
          dict[n-1]=1;
          dict[n]=1;
        }
      else{
            dict[i]=1;
            dict[i-1]=1;
            dict[i+1]=1;
        }

    }
  }
    for(int i=0;i<n;i++)
        if(dict[i]==1)
          count++;
      cout<<n-count<<endl;
  }
  return 0;
}
