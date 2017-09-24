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
  void topological_sort_util(int ,vector<bool> &, stack<int> &);
public:
  Graph(int v);
  void _addEdge(int u,int v);
  void DFS(int s);
  void topological_sort();
};
Graph::Graph(int v)
{
  this->v = v;
  adj  = new list<int>[v];
}
 void Graph::_addEdge(int u,int v)
 {
   adj[u].push_back(v);
 }
void Graph::topological_sort_util(int s, vector<bool> &vis,stack<int> &st)
{
  vis[s]==true;
  auto it = adj[s].begin();
  for(it;it!adj[s].end();++it)
    if(vis[*it]==0)
      topological_sort_util(*it,vis,st);
  st.push(s);    
}
void Graph::topological_sort(int s)
{
  stack<int>st;
  vector<bool> vis(v+1,0);

  topological_sort_util(s,vis,st)
}
int main()
{
  Graph g = Graph(8);
  g._addEdge(1,3);
  g._addEdge(2,3);
  g._addEdge(3,5);
  g._addEdge(1,3);
  g._addEdge(2,4);
  g._addEdge(4,6);
  g._addEdge(5,6);
  g._addEdge(6,7);
  return 0;
  //a-1 b-2 c-3 d-4 e-5 f-6 g-7
}
