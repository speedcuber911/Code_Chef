#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int n;
  for(;;)
  {
    int j,k;
    int count=0;
    cin>>n;
    if(n==0)
      break;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=n-1;i>=2;i--)
    {
      j=i-1;
      k=0;
      while(k<j)
      {
      if(a[i]>(a[j]+a[k]))
        {          
          count+=(j-k);
          k++;
        }
      else
        j--;
      }
    }
    cout<<count<<endl;
  }

return 0;
}
