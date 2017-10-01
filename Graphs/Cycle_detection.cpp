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
  bool cycle();
  bool is_cyclic(int i,vector<bool>&vis, vector<bool>&rec);
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
}
bool Graph::is_cyclic(int i,vector<bool>&vis, vector<bool>&rec)
{
  if(vis[i]==false)
  {
    cout<<i<<"  ";
    vis[i]=true;
    rec[i]=true;
    auto it = adj[i].begin();
    for(it;it!=adj[i].end();++it)
    {
      if(vis[*it]==false && is_cyclic(*it,vis,rec) == true)
        return true;
      else
        if(rec[*it]==true)
          return true;
    }
  }
    rec[i]=false;
    return false;
}
bool Graph::cycle()
{
  vector<bool>vis(v,0),rec(v,0);
  for(int i=0;i<v;i++)
    if(is_cyclic(i,vis,rec))
      return true;
  else
      return false;
}
int main()
{
  Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);
   if(g.cycle())
    cout<<"YES\n";
  else
    cout<<"NO\n";
  return 0;
}
