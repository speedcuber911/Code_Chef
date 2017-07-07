#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{

  int t;
  //cin>>t;
  t=1;
  while(t--)
  {
    int n;
    int count =0;
    cin>>n;
    vector<int>a(n);
    map<int,int>vis;
    for(int i=0;i<n;i++)
        {
          cin>>a[i];
          if(i+1>=a[i])
            count++;
        }
    cout<<count<<endl;
    for(int i=0;i<n;i++)
    {
      if(vis[a[i]]==1)
        continue;
      else
      {
        int j=i;
        while(1)
          {
            cout<<j+1<<" ";
            vis[j+1]=1;
            j=a[j]-1;
            if(a[i]==a[j])
              {
                vis[j+1]=1;
                cout<<j+1<<" ";
                break;
              }
          }
        cout<<endl;
      }
    }
  }
}
