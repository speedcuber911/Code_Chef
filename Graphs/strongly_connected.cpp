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
  list <int> * adj;
  void DFS_util(int ,vector<bool> &);
  Graph(int v);
  Graph transpose();
  bool strong();
  void addEdge(int u,int v);
  void DFS(int s, vector<bool>&vis);
};
Graph::Graph(int r)
{
  this->v = r;
  adj = new list<int>[r];
}
void Graph::addEdge(int u,int v)
{
  adj[u].push_back(v);
}
void Graph::DFS(int s,vector<bool>&vis)
{
  vis[s]=1;
  auto it = adj[s].begin();
  for(it;it!=adj[s].end();++it)
  {
    if(!vis[*it])
      DFS(*it,vis);
  }
}
Graph Graph::transpose()
{
  Graph _g = Graph(v);
  for(int i=0;i<v;i++)
  {
    auto it = adj[i].begin();
    for(it;it!=adj[i].end();++it)
    {
        _g.adj[*it].push_back(i);
    }
  }
  return _g;
}
bool Graph::strong()
{
  vector<bool>vis(v,0);
  DFS(0,vis);
  for(int i=0;i<v;i++)
    if(vis[i]==false)
      {
      cout<<"Returning false ";
      return false;
      }
  Graph gr = transpose();
  for(int i=0;i<v;i++)
    vis[i]=0;
  gr.DFS(0,vis);
  for(int i=0;i<v;i++)
    if(vis[i]==false)
      {
      // cout<<"Returning false on"<<;
      return false;
      }
  return true;
}
int main()
{
  Graph g = Graph(5);//DFS from one point, reverse the edges, DFS again from that point, if all visited then works
   g.addEdge(0, 1);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(3, 0);
   g.addEdge(2, 4);
   g.addEdge(4, 2);
  if(g.strong())
    cout<<"True\n";
  else
    cout<<"False\n";
  return 0;
}
