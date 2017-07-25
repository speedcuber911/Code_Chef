
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
    map<int,int>dict;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        dict[a[i]]=1;
        yap[a[i]]=1;
      }
    map<int,int>::iterator it;
    int count=0;
    for(it=dict.begin();it!=dict.end();++it)
      count++;
    cout<<count<<endl;
  }
  return 0;
}
