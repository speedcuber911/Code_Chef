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
  void dfs_util(int,vector<bool>&,stack<int>&,bool);
  bool strongly_connected();
  Graph transpose();
};
void Graph::dfs_util(int src,vector<bool> & vis,stack<int>&st,bool param)
{
  vis[src] = true;
  if(!param)
    cout<<src<<" ";
  for(auto it = adj[src].begin();it!=adj[src].end();++it)
    if(!vis[*it])
      dfs_util(*it,vis,st,param);
  if(param)//Prevents need to use 2 separate dfs functions
    st.push(src);//If DFS gets over push the source, 
}
Graph Graph::transpose()
{
  Graph gt = Graph(this->v);
  for(int i=0;i<this->v;i++)
    {
      auto it = adj[i].begin();
      for(it;it!=adj[i].end();++it)
        {
          gt.adj[*it].push_back(i);
        }
    }
  return gt;
}
bool Graph::strongly_connected()
{
  vector<bool>vis(v,0);
  stack<int>s;// used to store visit time of different vertices, line 39
  for(int i=0;i<v;i++)
    if(!vis[i])
      dfs_util(i,vis,s,1);
  cout<<endl;
  Graph g_trans = Graph(v);
  g_trans = transpose();
  cout<<endl;
  for(int i=0;i<v;i++)
    vis[i]=0;
  while(!s.empty())
  {
    if(!vis[s.top()])
      {
        g_trans.dfs_util(s.top(),vis,s,0);
        cout<<endl;
      }
    s.pop();
  }
  return true;
}
int main()
{
  Graph g = Graph(5);// Strongly connected componenets using kosaraju's
  g.addEdge(2,1);
  g.addEdge(1,0);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(3,4);
  g.strongly_connected();
  return 0;
}
