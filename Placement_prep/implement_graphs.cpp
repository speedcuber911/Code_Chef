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

using namespace std;

class graph{
  int v;
  list<int> *adj;
public:
  graph(int v)
  {
    this->v = v;
    this->adj = new list<int> [v];
  }
  void _addEdge(int i,int j)
  {
    adj[i].push_back(j);
    // adj[j].push_back(i);
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
    dfs_tree(vis,2);
    cout<<"\n";
  }

  void bfs(int start)
  {
    queue<int>qu;
    qu.push(start);
    vector<bool>vis(v,0);
    vis[start] = 1;
    while(!qu.empty())
    {
      int temp = qu.front();
      qu.pop();
      cout<<temp<<"\t";
      for(auto it = adj[temp].begin();it!=adj[temp].end();++it)
          if(!vis[*it])
            {
              qu.push(*it);
              vis[*it] = 1;
            }
    }
  }
  void sort_util(vector<bool>&vis,int start,stack<int>&st)
  {
      vis[start]=1;
      for(auto it = adj[start].begin();it!=adj[start].end();++it)
        {
          if(!vis[*it])
            sort_util(vis,*it,st);
        }
      st.push(start);
  }
  void topological_sort()
  {
    stack<int>st;
    vector<bool>vis(v,0);
    for(int i=0;i<v;i++)
      {
        if(!vis[i])
          sort_util(vis,i,st);
      }
    while(!st.empty())
      {
        cout<<st.top()<<"\t";
        st.pop();
      }
  }
};
int main()//bfs and dfs was included
{
  graph g = graph(4);
  g._addEdge(0,1);
  g._addEdge(0,2);
  g._addEdge(1,2);
  g._addEdge(2,0);
  g._addEdge(2,3);
  g._addEdge(3,3);  
  g.topological_sort();
}
