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


int main()//edit distance
{
  string a,b;
  cin>>a>>b;
  int n = a.size()+1;
  int m = b.size()+1;
  vector<vector<int> >arr(m,vector<int>(n,0));
  for(int i =0;i<n;i++)
    arr[0][i] = i;
  for(int i =0;i<m;i++)
    arr[i][0] = i;
  for(int i=1;i<m;i++)
    for(int j=1;j<n;j++)
    {
      if(a[i-1] != b[j-1])
        arr[i][j] = 1 + min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
      else
        arr[i][j] = arr[i-1][j-1];
    }
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
        cout<<arr[i][j]<<"\t";
      cout<<endl;
    }
  return 0;
}
