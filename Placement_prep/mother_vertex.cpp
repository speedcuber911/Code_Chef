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
  void addEdge(int i,int j)
  {
    adj[i].push_back(j);
    // adj[j].push_back(i);
  }
  void dfsutil(vector<bool>& visited,int u)
  {
    visited[v]=true;
    for(auto it=adj[u].begin();it!=adj[u].end();it++)
    {
      if(!visited[*it])
        dfsutil(visited,*it);
    }
  }
  int mother()
  {
    vector<bool>visited(v,false);
    int r;
    for(int i=0;i<v;i++)
    {
      if(visited[i]==false)
        dfsutil(visited,i);
      r=i;
    }
    for(int i=0;i<v;i++)
    {
      if(visited[i]==false)
        return r;
    }
    return -1;
  }
};

int main()
{
  graph g(7);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 3);
   g.addEdge(4, 1);
   g.addEdge(6, 4);
   g.addEdge(5, 6);
   g.addEdge(5, 2);
   g.addEdge(6, 0);
   cout<<g.mother()<<endl;
  return 0;
}
