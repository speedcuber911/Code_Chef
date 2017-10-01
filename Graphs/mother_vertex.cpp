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
  void DFS_util(int ,vector<bool> &,int &);
public:
  Graph(int v);
  void _addEdge(int u,int v);
  int DFS(int s);
  void find_mother();
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
void Graph::DFS_util(int s, vector<bool> &vis,int &ctr)
{
  vis[s] = 1;
  auto it = adj[s].begin();
  // cout<<s<<" ";
  ctr++;
  for(it;it!=adj[s].end();++it)
  {
    if(vis[*it]==0)
      DFS_util(*it,vis,ctr);
  }
}
int Graph::DFS(int s)
{
    vector<bool>vis(s+1,0);
    int ctr = 0;
    DFS_util(s,vis,ctr);
    // cout<<"For "<<s<<"-->"<<ctr<<endl;
    return ctr;
}
void Graph::find_mother()
{
  for(int i=0;i<=v;i++)
    if(DFS(i)==7)
      {
        cout<<"Mother vertex------->"<<i<<endlw;
        break;
      }
}
int main()
{
  Graph g = Graph(7);
  g._addEdge(0,1);
  g._addEdge(0,2);
  g._addEdge(1,3);
  g._addEdge(4,1);
  g._addEdge(5,2);
  g._addEdge(5,6);
  g._addEdge(6,4);
  g._addEdge(6,0);
  g.find_mother();
  return 0;
}
