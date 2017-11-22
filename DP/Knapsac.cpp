#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
//
// int knapsac(int w,int wt[],int val[],int n)
// {
//   if(w<=0 || n<0)
//     return 0;
//   if(wt[n]-w>0)
//     return knapsac(w,wt,val,n-1);
//   return max(val[n]+knapsac(w-wt[n],wt,val,n-1),knapsac(w,wt,val,n-1));
// }
/*DP implementaion of the same 2D table*/
int knapsac(int w,int wt[],int val[],int n)
{
    int k[n+1][w+1];
    for(int i=0;i<=n;i++)
      for(int j=0;j<=w;j++)
        {
          if(i==0 || j==0)
            k[i][j] =0;
          else
              if(wt[i-1]<=j)
                k[i][j] = max(val[i-1] +k[i-1][w-wt[i-1]],k[i-1][j]);
          else
                k[i][j] = k[i-1][j];
        }
    return k[n][w];
}
int main()
{
  int val[]  = {60,100,120};
  int wt[] = {10,20,30};
  int w = 50;
  cout<<knapsac(w,wt,val,3)<<"\n";
  return 0;
}
