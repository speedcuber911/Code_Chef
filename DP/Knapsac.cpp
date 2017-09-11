#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

// int knapsac(int w,int wt[],int val[],int n)
// {
//   if(w==0 || n==0)
//     return 0;
//   if(w<wt[n])
//     return knapsac(w,wt,val,n-1);
//   return max(knapsac(w-wt[n],val,n-1),knapsac(w,wt,val,n-1));
// }
/*DP implementaion of the same 2D table*/
int knapsac(int w,int wt[],int val[],int n)
{
  int knap[n+1][w+1]={0};
  int i,j;
  for(i=0;i<=n;i++)
    for(j=0;j<w;j++)
    {
      if(i==0 || j==0)
        knap[i][j]=0;// For 0 weight 0 elements in the array max is zero
      else
        if(w=>wt[i-1])
          knap[i][j] = max((val[i-1] + knap[i-1][w-wt[i-1]),knap[i-1][j]);
      else
        knap[i][j] = knap[i-1][j];
    }
    return knap[i][j];
}
int main()
{
  int val[]  = {60,100,120,240};
  int wt[] = {10,15,20,25};
  int w = 50;
  cout<<knapsac(w,wt,val,3)<<"\n";
  return 0;
}
