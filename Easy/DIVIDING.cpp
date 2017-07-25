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
  cin>>n;
  vector<long int>a(n);
  long int sum = float((1+n))*float(n)/2;
  long int tot=0;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      tot+=a[i];
    }
    if(sum==tot)
      cout<<"YES";
    else
      cout<<"NO";
  return 0;
}
