#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool compare(const vector<int> &r1, const vector<int> &r2)
{
  return((r1[0]*r1[1])>(r2[0]*r2[1]));
}
int main()
{
    int n;
    cin>>n;
    //L  B   H
    vector<vector<int > >a(3*n,vector<int>(3));
    for(int i=0;i<3*n;i+=3)
    {
      cin>>a[i][0]>>a[i][1]>>a[i][2];
      a[i+1][2] =  max(a[i][0],a[i][1]);//h is max of other 2
      a[i+1][1] =  min(a[i][0],a[i][1]);//b is  min of the same 2, no change in L
      a[i+1][0] = a[i][2];
      a[i+2][2] =  max(a[i][2],a[i][1]);
      a[i+2][0] =  min(a[i][2],a[i][1]);
      a[i+2][1] =  a[i][0];
    }
    cout<<"-------------Output\n";
    for(int i=0;i<a.size();i++)
      cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<endl;
      // sort(a.begin(),a.end(),compare);-
      // for(int i=0;i<n;i++)
      //   cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
  }
