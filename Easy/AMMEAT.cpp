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
  long long int m,r;
  int count=1;
  cin>>m;
  vector<long long int>a(n);
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
  sort(a.begin(),a.end());
  r=a[n-1];
  if(r>=m)
    cout<<count<<endl;
  else
  {
    int i;
    bool flip=0;
    for(i=n-2;i>=0;i--)
    {
      r+=a[i];
      count++;
      if(r>=m)
      {flip=1;
        break;
      }
    }
    if(flip==1)
      cout<<count<<endl;
    else
      cout<<-1<<endl;
  }
}
return 0;
}
