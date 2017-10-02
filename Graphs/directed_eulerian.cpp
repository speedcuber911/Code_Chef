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

class Graph{
  int v;
  list<int> *adj;
  int * in;
public:
  Graph(int r)
  {
    this->v = r;
    adj = new list<int>[r];
    in = new int[v];
    for(int i=0;i<v;i++)in[i]=0;
  }
  void addEdge(int u,int v)
  {
    adj[u].push_back(v);
    in[v]++;
  }
  void dfs_util(int src, vector<bool> &vis)
  {
    vis[src] = true;
    for(auto it= adj[src].begin();it!=adj[src].end();++it)
      if(!vis[*it])
        dfs_util(*it,vis);
  }
  Graph transpose()
  {
    Graph gt = Graph(this->v);
    for(int i=0;i<this->v;i++)
    {
      auto it = this->adj[i].begin();
      for(it;it!=this->adj[i].end();++it)
          gt.adj[*it].push_back(i);
    }
    return gt;
  }
  bool connected()
  {
    int j;
    for(j=0;j<v;j++)
      if(adj[j].size()!=0)
        break;
    vector<bool>vis(v,0);
    // if(i==v)
    //   return true;
    dfs_util(j,vis);
    for(int i=0;i<v;i++)
      if(vis[i]==0)
        return false;
    for(int i=0;i<v;i++)vis[i]=0;
    Graph g_rev = this->transpose();
    g_rev.dfs_util(0,vis);
    for(int i=0;i<v;i++)
      if(vis[i]==0)
        return false;
    return true;
  }
  bool eulerian()
  {
    if(!connected())
      return false;
    for(int i=0;i<v;i++)
      if(adj[i].size()!=in[i])
        return false;
    return true;
  }
};

int main()
{
  Graph g = Graph(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 0);
  if(g.eulerian())
    cout<<"Eulerian\n";
  else
    cout<<"Not Eulerian\n";

  return 0;
}
