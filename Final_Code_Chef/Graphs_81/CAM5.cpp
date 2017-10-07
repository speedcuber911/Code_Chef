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
  long long int v;
  list<long long int> *adj;
public:
  Graph(long long int r)
  {
    this->v = r;
    adj = new list<long long int>[r];
  }
  void addEdge(long long int u,long long int v)
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
  long long int connected()
  {
    vector<bool>vis(v,0);
    long long int ctr=0;
    for(int i=0;i<v;i++)
      if(vis[i]==0)
      {
        DFS_util(vis,i);
        ctr++;
      }
  return ctr;
}

};

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    Graph g = Graph(n);
    int e;
    cin>>e;
    int x,y;
    while(e--)
    {
      cin>>x>>y;
      g.addEdge(x,y);
    }
    cout<<g.connected()<<"\n";
  }
  return 0;
}
