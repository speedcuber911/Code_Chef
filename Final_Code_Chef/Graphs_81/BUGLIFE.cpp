#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph{
public:
int v;
int ** adj;
void DFS_util(int ,vector<bool> &);
Graph(int v);
void addEdge(int u,int v);
bool bipartite_util(int s,int color[]);
bool bipartite();
int DFS(int s);
};
Graph::Graph(int r)
{
  this->v = r;
  adj = new int*[v];
  for(int i=0;i<v;i++)
    adj[i] = new int[v];
  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
      adj[i][j] = 0;
}
void Graph::addEdge(int u,int v)
{
  adj[u][v]=1;
  adj[v][u]=1;
}
bool Graph::bipartite_util(int s,int color[])
{
  color[s] = 1;
  queue<int>q;
  q.push(s);
  while(!q.empty())
  {
    int r = q.front();
    q.pop();
    if(adj[r][r]==1)
      return false;
    for(int i=1;i<v;i++)
    {
      if(adj[r][i]==1 && color[i]==-1)
        {
          color[i] = 1 - color[r];
          q.push(i);
        }
      else
        if(adj[r][i]==1 && color[i] == color[r])
          return false;
    }
  }
  return true;
}
bool Graph::bipartite()
{
  int color[v];
  for(int i=1;i<v;i++)
    color[i] = -1;
  for(int i=1;i<v;i++)
  {
    if(color[i]==-1)
      if(bipartite_util(i,color)==false)
        return false;
  }
  return true;
}
int main()
{
  int t;
  cin>>t;
  for(int i=1;i<=t;i++)
  {
    int n;
    cin>>n;
    Graph g = Graph(n+1);
    int x,y;
    int m;
    cin>>m;
    while(m--)
    {
      cin>>x>>y;
      if(x==-1)
        break;
      g.addEdge(x,y);
    }
    if(g.bipartite())
      cout<<"Scenario #"<<i<<":"<<endl<<"Suspicious bugs found!\n";
    else
      cout<<"Scenario #"<<i<<":"<<endl<<"No suspicious bugs found!\n";
  }
  return 0;
}
