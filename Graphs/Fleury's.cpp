#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>

using namespace std;

class Graph
{
  int v;
  list<int> *adj;
public:
  Graph(int r)
  {
    this->v = r;
    adj = new list<int>[r];
  }
  void addEdge(int u,int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void DFS_util(vector<bool>&vis,int src)
  {
    vis[src]=1;
    auto it = adj[src].begin();
    for(it;it!=adj[src].end();++it)
    {
      if(!vis[*it])
        DFS_util(vis,*it);
    }
  }
};

// Get back to all subsidaries of tarjan's particuarly minimum
//visited time and discovery time definitions
