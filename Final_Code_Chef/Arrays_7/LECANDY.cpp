#include<iostream>

using namespace std;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	int c ;
	cin>>c;
	int temp;
	for(int i=0;i<n;i++)
		{
			cin>>temp;
			c = c-temp;
		}
	if(c>=0)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}
return 0;
}
