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
  int count=0;
  while(t--)
  {
    vector<int>x(6);
    for(int i=0;i<6;i++)
      cin>>x[i];
    int a,b,c;
    a = pow((x[0]-x[2]),2) + pow((x[1]-x[3]),2);
    b = pow((x[2]-x[4]),2) + pow((x[3]-x[5]),2);
    c = pow((x[0]-x[4]),2) + pow((x[1]-x[5]),2);    
    if(a==(b+c)|| b==(a+c)|| c==(a+b))
      count++;
  }
  cout<<count<<endl;
}
