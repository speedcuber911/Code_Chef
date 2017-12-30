#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>
#include<queue>

using namespace std;

int main()//binomial_coeff
{
int n,r;
cin>>n>>r;
n++;
vector<vector<int> >bion(n,vector<int>(n,0));
for(int i=1;i<n;i++)
  for(int j=0;j<=i;j++)
  {
    if(i==j || j==0)
      bion[i][j]=1;
    else
      if(j==1)
        bion[i][j] = i;
    else
        bion[i][j] = bion[i-1][j] + bion[i-1][j-1];
  }
cout<<"The value is-------->"<<bion[n-1][r]<<endl;
return 0;
}
