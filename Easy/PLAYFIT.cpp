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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n,x,y;
    cin>>t;
    while(t--)
    {
        int max=0;
      cin>>n;
      cin>>y;
      for(int i=1;i<n;i++)
      {
      cin>>x;
      if(x<y)
        y=x;
      else
        if(x-y>max)
          max=x-y;
    }
    if(max==0)
      cout<<"UNFIT\n";
    else
      cout<<max<<endl;
    }
    return 0;
  return 0;
}
