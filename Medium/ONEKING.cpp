#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[0] < v2[0];
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long int n,m;
    cin>>n;
    m=1;
    vector<vector <int> > a(n,vector<int>(2));
    for(int i=0;i<n;i++)
      {
        cin>>a[i][0]>>a[i][1];
      }
      int check = a[0][1];
    sort(a.begin(),a.end(),sortcol);
    for(int i=0;i<n-1;i++)
      {
          if(a[i][1]>check)
            {
              check = a[i][1];
              m++;
            }
          if(check>=a[i+1][0])
          {
            continue;
          }
        }
        cout<<m<<endl;
      }
  return 0;
}
