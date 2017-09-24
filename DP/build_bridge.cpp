#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool sortcol(const vector<int>v1,const vector<int>v2)
{
  if(v1[0]==v2[0])
    return v1[1]<v2[0];
  return v1[0]<v2[0];
}

int main()
{
  int n = 4;
  int arr2[] = {6,4,2,1};
  int arr1[] = {2,3,6,5};
  vector<vector<int> >r(n,vector<int>(2));
  for(int i=0;i<n;i++)
    {
      r[i][0] = arr1[i];
      r[i][1] = arr2[i];
    }
  sort(r.begin(),r.end(),sortcol);
  for(int i=0;i<n;i++)
      cout<<r[i][0]<<" ";
  cout<<endl;
    for(int i=0;i<n;i++)
      cout<<r[i][1]<<" ";
  cout<<endl;
  vector<int>lis(n,1);
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
    {
          if(r[1][i]>r[1][j] && lis[i] < lis[j] +1)
            lis[i] = lis[j]+1;
    }
  int max =0;
  for(int i=0;i<n;i++)
    if(max<lis[i])
      max = lis[i];
  cout<<max<<endl;
}
