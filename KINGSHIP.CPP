#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
    {
    	long int n;
    	cin>>n;
    	vector<long long int>a(n);
    	long long int sum=0;
    	vector<long long int>b;
    	for(int i=0;i<n;i++)
    		cin>>a[i];
    	sort(a.begin(),a.end());
    	for(int i=1;i<n;i++)
        sum+=a[0]*a[i];
    	cout<<sum<<endl;

    }
   }
