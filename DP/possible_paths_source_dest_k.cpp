#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

// int walks(vector<vector<int> >graph,int u,int v,int k)
// {
//   if(k==0 || u==v)
//     return 1;
//   if(k==1 && graph[u][v])
//     return 1;
//   if(k<=0)
//     return 0;
//   int count =0;
//   for(int i=0;i<graph.size();i++)
//     if(graph[u][i] ==1)
//       count += count_walks(graph,u,i,k-1);
//   return count;
// }

int opti_walk(vector<vector<int> >graph,int u,int v,int k)
{
    int n = graph.size();
    int dp[n][n][k+1];
    for(int i=0;i<=k;i++)// Edges from 0 to k
      for(int j=0;j<n;j++)// For source
        for(int t=0;t<n;t++)// For destination
        {
          dp[j][t][i] = 0;
          if(i==0 &&  j==t)
            dp[j][t][i] = 1;
          if(i==1 && graph[j][t])
            dp[j][t][i] = 1;
          if(i>0)
              for(int r;r<n;r++)
                if(graph[j][r])
                  dp[j][t][i] += dp[r][t][i-1];
        }
    return dp[u][v][k];
}
int main()
{
  int n;
  cin>>n;
  n++;
  vector<vector<int> >arr(n,vector<int>(n,0));
  int e;
  cin>>e;
  int x,y;
  for(int i=0;i<e;i++)
    {
      cin>>x>>y;
      arr[x][y] = 1;
    }
  int u,v;
  cin>>u>>v;    
  // walks(arr,u,v,k);
  cout<<opti_walk(arr,u,v,e);
  return 0;
}
