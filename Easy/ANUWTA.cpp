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
    long long int n;
    cin>>n;
    long long int sum=0;
    sum+= (3*n+(n*(n-1)/2));
    cout<<sum-n<<endl;
  }
  }
