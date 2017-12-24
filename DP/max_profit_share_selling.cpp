#include<iostream>
#include<vector>
#include<map>

using namespace std;

int max_profit(vector<int>arr,int k)
{
  int n = arr.size();
  vector<vector<int> >tab(n+1,vector<int>(n+1));
  for(int i=1;i<=k;i++)
    for(int j=1;j<n;j++)
    {
      int maxed = INT_MIN;
      for(int m=0;m<j;m++)
        maxed = max(maxed,arr[j]-arr[m] + tab[i-1][m]);
      tab[i][j] = max(tab[i][j-1],maxed);
    }
  return tab[k][n-1];  
}
int main()
{
  int k;
  cin>>k;
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<max_profit(arr,k);
  return 0;
}
