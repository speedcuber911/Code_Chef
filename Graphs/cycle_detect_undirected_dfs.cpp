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
  int v;
  list<int> * adj;
  void DFS_util(int ,vector<bool> &);
public:
  Graph(int v);
  void addEdge(int u,int v);
  bool is_cyclic(int i,vector<bool>&vis,int parent);
  void det_cycle(int n);
  int DFS(int s);
};

Graph::Graph(int r)
{
  this->v = r;
  adj = new list<int>[r+1];
}
void Graph::addEdge(int u,int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}
bool is_cycle(int i,vector<bool> & vis,int parent)
{
  vis[i] == true;
  auto it = adj[i].begin();
  for(it;it!=adj[i].end();++it)
  {
    if(!vis[*it])
      if(is_cycle(*it,vis,i))
        return true;
    else
      {
        if(*it!=parent)
          return true;
      }
  }
  return false;
}
bool det_cycle(int n)
{
  vector<bool>vis(n,0);
  for(int i=0;i<v;i++)
  {
    if(!vis[i])
      if(is_cycle(i,vis,-1))
        return true;
  }
  return false;
}
int main()
{
  return 0;
  Graph g1(5);
 g1.addEdge(0, 1);
 g1.addEdge(1, 2);
 g1.addEdge(2, 3);
 g1.addEdge(3, 4);
 g.det_cycle(5);
}
