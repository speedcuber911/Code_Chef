#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

int matrix_order(vector<int>p)
{
    int n = p.size();
    int j;
    vector<vector<int> >tab(n,vector<int>(n,0));
    int q;
    for(int l=2;l<p.size();l++)
    {
      for(int i=0;i<p.size()-l;i++)
      {
        j = i+l;
        tab[i][j] = INT_MAX;;
        for(int k=i+1;k<j;k++)
        {
          q = tab[i][k] + tab[k][j] + p[i]*p[k]*p[j];
          cout<<"For "<<i<<" "<<j<<" value is "<<q<<endl;
          tab[i][j] = min(tab[i][j],q);
        }
      }
    }
    for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
          cout<<tab[i][j]<<"\t";
        cout<<endl;
      }
      return 0;
}
int main()
{
  vector<int>arr(5);
  arr[0] = 2;
  arr[1] = 3;
  arr[2] = 6;
  arr[3] = 4;
  arr[4] = 5;
  cout<<matrix_order(arr)<<endl;
  return 0;
}
