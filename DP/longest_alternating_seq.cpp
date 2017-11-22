#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
//Longest zigzag seq
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  // vector<vector<int> >aux(n,vector<int>(2,1));
  int aux[n][2];
  for(int i=0;i<n;i++)
    {
      aux[i][0] = 1;
      aux[i][1] = 1;
     }
  int res = 1;
  for(int i=1;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(arr[i] > arr[j])
          if(aux[j][1] + 1 > aux[i][0])
            aux[i][0] = aux[j][1] + 1;
        if(arr[i] < arr[j])
          if(aux[j][0] + 1 > aux[i][1])
            aux[i][1] = aux[j][0] + 1;
      }
      if(res<max(aux[i][0],aux[i][1]))
        res = max(aux[i][0],aux[i][1]);
    }
cout<<res<<endl;
  return 0;
}
