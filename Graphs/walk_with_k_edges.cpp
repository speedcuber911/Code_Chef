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
  int V;
  vector<vector<int> >adj;
public:
  Graph(int r)
  {
    this->V = r;
    adj.resize(r);
    for(int i=0;i<r;i++)
      adj[i].resize(r,0);
  }
  void addEdge(int u,int v)
  {
    adj[u][v]=1;
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
  int walks(int u,int v,int k)
  {
    if(k==0 && u==v)
      return 1;
    if(k==1 && adj[u][v]==1)
      return 1;
    if(k<=0)
      return 0;
    int count=0;
    for(int i=0;i<V;i++)
      {
        if(adj[u][i]==1)
          count+= walks(i,v,k-1);
      }
    return count;
  }
};
int main()
{
  int n;
  cin>>n;
  int e;//no. of edges
  cin>>e;
  int x,y;
  Graph g = Graph(n);// Put a default graph in constructor
  for(int i=0;i<e;i++)
  {
    cin>>x>>y;
    g.addEdge(x,y);
  }
  cout<<"Provide source, destination and length\n";
  int u,v,k;
  cin>>u>>v>>k;
  cout<<g.walks(u,v,k)<<endl;
  return 0;
}
