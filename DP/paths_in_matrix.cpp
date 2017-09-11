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
  vector<int>a(4);
  vector<vector <int> >a(3,vector <int>(3));
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
      {
        if(i==0 || j==0)
          a[i][j] = 1;
      }
  }
  for(int i=1;i<3;i++)
  {
    for(int j=1;j<3;j++)
    {
        a[i][j] = a[i-1][j] + a[i-1][j-1] + a[i][j-1];
    }
  }
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
      {
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
  }

  return 0;
}
