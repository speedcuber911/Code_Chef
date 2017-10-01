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
public:
  Graph(int r)
  {
    this->v = r;
    adj = new list<int>[r];
  }
  void addEdge(int u,int v)
  {
    adj[u].push_back(v);
  }
  void dfs_util(int,vector<bool>&,stack<int>&);
  bool strongly_connected();
};
void Graph::dfs_util(int src,vector<bool> & vis,stack<int>&st)
{
  vis[src] = true;
  for(auto it = adj[src].begin();it!=adj[src].end();++it)
    if(!vis[*it])
      dfs_util(*it,vis,st);
  st.push(src);
}
bool Graph::strongly_connected()
{
  vector<bool>vis(v+1,0);
  stack<int>s;
  for(int i=0;i<v;i++)
    if(!vis[i])
      dfs_util(i,vis,s);
  cout<<endl;
  while(!s.empty())
    {
      cout<<s.top()<<"\n";
      s.pop();
    }
  return true;
}
int main()
{
  Graph g = Graph(5);
  g.addEdge(2,1);
  g.addEdge(1,0);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(3,4);
  g.strongly_connected();
  return 0;
}
