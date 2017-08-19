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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  long long int sum =0,temp;
  long long int counter=0;
  vector<long long int>a(32,0);
  for(int i=0;i<n;i++)
  {
      cin>>temp;
      counter=0;
      while(temp!=0)
      {
        if(temp&1)
          a[counter]++;
        counter++;
        temp >>= 1;
      }
  }
      for(int i=0;i<a.size();i++)
      {
        if(a[i]!=0)
          sum += (a[i]*(a[i]-1)/2)*pow(2,i);
      }
      cout<<sum<<endl;
  return 0;
}
