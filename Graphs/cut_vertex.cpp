#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<list>
#include<queue>

const int maxs =  10001;

int parent [maxs];
int child  [maxs];
int low    [maxs];
int tym    [maxs];
bool seen  [maxs];
bool is_cut[maxs];

using namespace std;

class Graph{
  int v;
  list<int> * adj;
  void DFS_util(int ,vector<bool> &);
public:
  Graph(int v);
  void _addEdge(int u,int v);
  int DFS(int s);
};

Graph::Graph(int r)
{
  this->v = r;
  adj = new list<int>[r+1];
}
void Graph::_addEdge(int u,int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::DFS(int s)
{
  static int t = 0;
  seen[s] = true;
  low[s]=tym[s] = t++;
  auto it = adj[s].begin();
  for(it;it!=adj[s].end();++it)
  {
    int curr = *it;
    if(curr == parent[s])
      continue;
    if(!seen[curr])
    {
      child[s]++;
      parent[curr]=s;
      DFS(curr);
       low[s] = min(low[s],low[curr]);
      if(low[curr] >= tym[s])
        is_cut[s]=true;
    }
    else
    {
      low[s] = min(low[s],tym[curr]);
    }
  }
}
int main()
{
  int t;
  cin>>t;
  int c = 1;
  while(t--)
  {
    int v,e;
    cin>>v>>e;
    Graph g = Graph(v);
    int a,b;
    for(int i=0;i<e;i++)
      {
        cin>>a>>b;
        g._addEdge(a,b);
      }
      parent[a] =-1;
      g.DFS(a);
      if(child[a]>1)
        is_cut[a] = true;
      else
        is_cut[a] = false;
      int c
      for(int i=0;i<maxs;i++)
        if(is_cut[i]==true)
          ctr++;
  }
  return 0;
}
