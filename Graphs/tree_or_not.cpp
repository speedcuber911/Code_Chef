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
  bool connected()
  {
    vector<bool>vis(v,0);
    DFS_util(vis,0);
    for(int i=0;i<v;i++)
      if(vis[i]==0)
        return false;
  cout<<"-Is connected\n"      ;
  return true;
  }
  bool mod_dfs(int src,int parent,vector<bool>&vis)
  {
    vis[src]=1;
    for(auto it=adj[src].begin();it!=adj[src].end();++it)
    {
      if(!vis[*it])
          mod_dfs(*it,src,vis);
      else
        if(parent!=*it)
          return false;
    }
    return true;
  }
  bool iscyclic()
  {
    vector<bool>vis(v,0);
    int par = -1;
      if(mod_dfs(0,par,vis))
        return true;    
    return false;

  }
  bool tree_check()
  {
    if(connected()==true && iscyclic()==true)
      return true;
    return false;
  }
};

int main()// Check if graph is tree or not
{
  Graph g1(5);
  g1.addEdge(1, 0);
  g1.addEdge(0, 2);
  g1.addEdge(0, 3);
  g1.addEdge(3, 4);
  if(g1.tree_check())
    cout<<"Tree\n";
  else
    cout<<"Not tree\n";
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    if(g2.tree_check())
      cout<<"Tree\n";
    else
      cout<<"Not tree\n";

  return 0;
}
