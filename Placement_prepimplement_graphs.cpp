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

class graph{
  int v;
  list<int> adj*;
public:
  graph(int v)
  {
    this->v = v;
    this->adj = new list<int> [v];
  }
  void _addEdge(int i,int j)
  {
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  void dfs_tree(vector<bool>&vis,int u)
  {
      vis[u] = true;
      cout<<u<<"\t";
      for(auto it = adj[u].begin();it!=adj[u].end();++it)
        {
          if(!vis[*it])
            dfs_tree(vis,*it);
        }
  }
  void dfs()
  {
    vector<bool>vis(v,0);
    dfs_tree(vis,1);
  }
};
int main()
{
  graph g = graph(4);
  g._addEdge(1,2);
  g._addEdge(2,3);
  g._addEdge(1,3);
  g.dfs();
}
