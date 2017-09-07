#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<queue>

using namespace std;

class Graph
{
    int v;
    list<int>*adj;
  public:
    Graph(int v);
    void addEdge(int v,int w);
    void bfs(int s);
};
Graph :: Graph(int v)
{
  adj = new list<int>[v];
  this->v = v;
}
void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
}
void Graph::bfs(int s)
{
    queue<int>q;
    vector<bool>vis(v+1,0);
    q.push(s);
    while(!q.empty())
    {
      int r = q.front();
      q.pop();
      cout<<r<<" ";
      auto it = adj[r].begin();
      for(it;it!=adj[r].end();++it)
      {
        if(vis[*it]==0)
        {

          vis[*it]=1;
          q.push(*it);
        }
      }
    }
}
int main()
{
Graph g(7);
g.addEdge(1,2);
g.addEdge(2,1);
g.addEdge(1,3);
g.addEdge(3,1);
g.addEdge(2,4);
g.addEdge(4,2);
g.addEdge(3,4);
g.addEdge(4,3);
g.addEdge(3,5);
g.addEdge(5,3);
g.addEdge(4,6);
g.addEdge(6,4);
cout<<"BFS traversal ";
g.bfs(1);
return 0;
}
