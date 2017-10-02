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
  long long int DFS_util(vector<bool>&vis,long long int src,long long int &ctr)
  {
    vis[src]=1;
    ctr++;
    auto it = adj[src].begin();
    for(it;it!=adj[src].end();++it)
    {
      if(!vis[*it])
        DFS_util(vis,*it,ctr);
    }
    return ctr;
  }
  long long int connected()
  {
    vector<bool>vis(v,0);
    long long int ctr=0;
    long long int comp = 0;
    long long int comp2 = 1;
    for(long long int i=1;i<v;i++)
      {
        comp=0;
        if(vis[i]==0)
          {
            ctr++;
            comp2 *= DFS_util(vis,i,comp);
            comp2 = comp2%1000000007;
          }
      }
    cout<<(ctr)%mod<<" ";
      return comp2;
  }
};
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long int n,m;
    cin>>n>>m;
    Graph g = Graph(n+1);
    long long int x,y;
    for(long long int i=0;i<m;i++)
    {
      cin>>x>>y;
      g.addEdge(x,y);
    }
    long long int r = g.connected();
    cout<<r<<endl;
  }
  return 0;
}
