#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph{
public:
  int v;
  vector<vector<int> >adj;
  Graph(int);
  void _addEdge(int,int);
  void t_closure();
  void disp(vector<vector<int> >);
};

void Graph::disp(vector<vector<int> >reach)
{
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    {
      cout<<reach[i][j]<<" ";
    }
    cout<<endl;
  }
}
Graph::Graph(int r)
{
  this->v = r;
  adj.resize(v, vector<int>(v,0));
}
void Graph::_addEdge(int u,int r)
{
  adj[u][r]=1;
}
void Graph::t_closure()
{
  vector<vector<int> >reach(v,vector<int>(v,0));
  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
      reach[i][j] = adj[i][j];
  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
      for(int k=0;k<v;k++)
      {
        if(reach[i][j] && reach[j][k])
          reach[i][k]=1;
      }
  disp(reach);
}
int main()
{
  Graph g = Graph(7);
  g._addEdge(0,1);
  g._addEdge(0,2);
  g._addEdge(1,3);
  g._addEdge(4,1);
  g._addEdge(5,2);
  g._addEdge(5,6);
  g._addEdge(6,4);
  g._addEdge(6,0);
  cout<<"Main graph \n\n";
  g.disp(g.adj);
  cout<<"Closure \n";
  g.t_closure();
  return 0;
}
