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
  void _addEdge(int u,int v);
  void DFS(int s);
};

Graph::Graph(int r)
{
  this->v = r;
  adj = new list<int>[r+1];
}
void Graph::_addEdge(int u,int v)
{
  adj[u].push_back(v);
}
void Graph::DFS_util(int s, vector<bool> &vis)
{
  vis[s] = 1;
  auto it = adj[s].begin();
  cout<<s<<" ";
  for(it;it!=adj[s].end();++it)
  {
    if(vis[*it]==0)
      DFS_util(*it,vis);
  }
}
void Graph::DFS(int s)
{
    vector<bool>vis(s+1,0);
    DFS_util(s,vis);
}
int main()
{
  Graph g = Graph(5);
  g._addEdge(0,1);
  g._addEdge(1,0);
  g._addEdge(0,4);
  g._addEdge(4,0);
  g._addEdge(4,2);
  g._addEdge(2,4);
  g._addEdge(2,1);
  g._addEdge(1,2);
  g._addEdge(2,3);
  g._addEdge(3,2);
  g._addEdge(1,3);
  g._addEdge(3,1);
  g.DFS(3);
  return 0;
}
