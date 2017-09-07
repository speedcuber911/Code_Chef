#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

class Graph
{
  int v;
  list<int> *adj;
  void DFSutil(int s,bool *v);
public:
  Graph(int v);
  void addEdge(int s,int v);
  void DFS(int s);
};

Graph::Graph(int v)
{
  this->v = v;
  adj  = new list<int>[v];
}
void Graph::addEdge(int s,int v)
{
  adj[s].push_back(v);
}
void Graph::DFSutil(int s,bool *v)
{
  v[s] = true;
  cout<<s<<" ";
  list<int>:: iterator it;
  for(it=adj[s].begin();it!=adj[s].end();++it)
    if(v[*it]==0)
      DFSutil(*it,v);

}
void Graph::DFS(int s)
{
    bool * visited  = new bool[v];
    memset(visited,0,v);
    DFSutil(s,visited);
}

int main()
{
Graph g(4);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(2,0);
g.addEdge(2,3);
g.addEdge(3,3);
g.DFS(2);
return 0;
}
