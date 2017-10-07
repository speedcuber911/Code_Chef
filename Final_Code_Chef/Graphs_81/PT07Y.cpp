#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<int>* adj;
public:
  Graph(int r)
  {
    this->v = r;
    adj = new list<int>[r];
  }
  void addEdge(int x,int y)
  {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bool dfs_cyclic(vector<bool>&vis,int s,int parent)
  {
    vis[s]=1;
    for(auto it = adj[s].begin();it!=adj[s].end();++it)
      {
        if(!vis[*it])
          dfs_cyclic(vis,*it,s);
        else
          if(*it!=parent)
            {      
            return false;
            }
      }
      for(int i=1;i<v;i++)
        if(vis[i]==0)
          return false;
      return true;
  }
  bool check_t()
  {
    vector<bool>vis(v,0);
    if(dfs_cyclic(vis,1,-1))
      cout<<"YES\n";
    else
      cout<<"NO\n";
    return true;
  }
};
int main()
{
  int n;
  cin>>n;
  Graph g(n+1);
  int e;
  cin>>e;
  int x,y;
  for(int i=0;i<e;i++)
    {
      cin>>x>>y;
      g.addEdge(x,y);
    }
  g.check_t();
  return 0;
}
