#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph
{
    int v;
    list <int> *adj;
  public:
    Graph(int v);
    void _addEdge(int u,int v);
    void _BFS(int s);
};
Graph::Graph(int n)
{
  this->v = n;
  adj = new list<int>[n+1];
}
void Graph::_addEdge(int u,int v)
{
  adj[u].push_back(v);
}
void Graph::_BFS(int t)
{
  queue<int>q;
  q.push(t);
  vector<bool> vis(v+1,0);
  vis[t]=1;
  while(!q.empty())
  {
    int s = q.front();
    q.pop();
    cout<<s<<"  ";
    auto it = adj[s].begin();
    for(it;it!=adj[s].end();++it)
    {
      if(vis[*it]==0)
      {
        vis[*it] = 1;
        q.push(*it);
      }
    }
  }
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
  g._BFS(3);
  return 0;
}
