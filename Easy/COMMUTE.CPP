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
    int n;
    cin>>n;
    vector<vector <int> > a (n, vector<int>(3));
    for(int i=0;i<n;i++)
      for(int j=0;j<3;j++)
        cin>>a[i][j];
    long int time=0;
    time+= a[0][0];
    time+= a[0][1];
    for(int i=1;i<n;i++)
    {
                    
    }
  }
}
