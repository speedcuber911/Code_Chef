#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
#define N 4
#define INF INT_MAX

int min_cost(int cost[N][N],int s,int d)
{
    if(s== d || s+1 == d)
      return cost[s][d];
    int min_e = cost[s][d];
    for(int i=s+1;i<d;i++)
      {
        int t = min_cost(cost,s,i) + min_cost(cost,i,d);
        if(t<min_e)
           min_e = t;
      }
      return min_e;
}
// Using topological sorting is better
int min_cost_2(int cost[N][N],int s,int d)
{
  vector<int>dist(N,INT_MAX);
  dist[0] = 0;
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
        if(dist[j] > dist[i] + cost[i][j])
          dist[j] = dist[i] + cost[i][j];
  return dist[N-1];
}
int main()
{
  // int INF = INT_MAX;
  int cost[N][N] = {
                      {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
  cout<<min_cost(cost,0,3);
  cout<<min_cost_2(cost,0,3);
  return 0;
}
