#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
  int v;
  list<int> * adj;
  void topological_sort_util(int ,vector<bool> &, stack<int> &);
public:
  Graph(int v);
  void _addEdge(int u,int v);
  void DFS(int s);
  void topological_sort(int s);
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
  vis[s]=true;
  auto it = adj[s].begin();
  for(it;it!=adj[s].end();++it)
    if(vis[*it]==0)
      topological_sort_util(*it,vis,st);
  st.push(s);
  cout<<s<<" ";
}
void Graph::topological_sort(int s)
{
  stack<int>st;
  vector<bool> vis(v+1,0);
  for(int i=1;i<v;i++)
    if(vis[i]==0)
      topological_sort_util(i,vis,st);
  cout<<endl;
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
}
int main()
{
  Graph g(6);
     g._addEdge(5, 2);
     g._addEdge(5, 0);
     g._addEdge(4, 0);
     g._addEdge(4, 1);
     g._addEdge(2, 3);
     g._addEdge(3, 1);
     g.topological_sort(1);
  return 0;
  //a-1 b-2 c-3 d-4 e-5 f-6 g-7
}
