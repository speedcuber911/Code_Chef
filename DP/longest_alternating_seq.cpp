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
      aux[i][0] =1;// For the inreasing ones
      aux[i][1] =1;// For decreasing ones
    }
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
    {
      if(arr[i] > arr[j] && aux[j][1] + 1 >aux[i][0])
        aux[i][0] = aux[j][1] +1;
      if(arr[i] < arr[j] && aux[j][0] + 1 > aux[i][1])
        aux[i][1] = aux[j][0] +1;
    }
  int maxed = INT_MIN;
  for(int i=0;i<n;i++)
      maxed = max(maxed,(max(aux[i][0],aux[i][1])));
  cout<<maxed<<endl;

  return 0;
}
