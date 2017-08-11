#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int row,col;
int mine(vector<vector<int> > a,int m,int n)
{
    if(m<0 || n<0)
      return INT_MAX;
    if(n==0 && m==0)
      return a[0][0];
    return a[m][n] + min(mine(a,m-1,n-1),min(mine(a,m-1,n),mine(a,m,n-1)));
}
int main()
{
  cin>>row>>col;
  vector<vector <int> >a(row, vector<int> (col));
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    {
      cin>>a[i][j];
    }
  int m,n;
  cin>>m>>n;
  cout<<mine(a,m,n)<<endl;
  return 0;
}
