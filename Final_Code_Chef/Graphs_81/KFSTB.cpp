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
    v =r;
    adj = new list<int>[r];
  }
  void addEdge(int x,int y)
  {
      adj[x].push_back(y);
  }
  int dfs_util(int s,int t,vector<bool>&vis,int &ctr)
  {
    if(s==t)
      {
      ctr++;
      ctr %= 1000000007;
      }
    vis[s]=1;
    for(auto it=adj[s].begin();it!=adj[s].end();++it)
      if(!vis[*it])
        dfs_util(*it,t,vis,ctr);
  return ctr;
  }
  int paths(int s,int t)
  {
    int ctr;
    vector<bool>vis(v,0);
    return
      dfs_util(s,t,vis,ctr);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int c,b,s,t;
    cin>>c>>b>>s>>t;
    Graph g = Graph(c+1);
    int x,y;
    for(int i=0;i<b;i++)
    {
      cin>>x>>y;
      g.addEdge(x,y);
    }
    cout<<g.paths(s,t)<<endl;
  }
}
