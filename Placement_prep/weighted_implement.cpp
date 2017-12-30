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

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class graph{
  int v;
  list<AdjListNode>*adj;
public:
  graph(int siz)
  {
    this->v = siz;
    adj = new list<AdjListNode> [v];
  }
  void addEdge(int u,int v,int w)
  {
    AdjListNode node = AdjListNode(v,w);
    adj[u].push_back(node);
  }
  void sort_util(int start,stack<int>&st,vector<bool>&vis)
  {
    vis[start] = true;
    for(auto it=adj[start].begin();it!=adj[start].end();++it)
    {
      AdjListNode node = *it;
      if(!vis[node.getV()])
        sort_util(node.getV(),st,vis);
    }
    st.push(start);
  }
  void longest_path()
  {
    stack<int>st;
    vector<bool>vis(v,0);
    for(int i=0;i<v;i++)
      if(!vis[i])
        sort_util(i,st,vis);
    vector<int>dist(v,INT_MIN);
    dist[1] = 0;
    while(!st.empty())
    {
      int u = st.top();
      st.pop();
      if(dist[u]!=INT_MIN)
        for(auto it = adj[u].begin();it!=adj[u].end();++it)
          if(dist[it->getV()] < dist[u] + it->getWeight())
            dist[it->getV()] = dist[u] + it->getWeight();
    }
    for(int i : dist)
    if(i==INT_MIN)
      cout<<"NINF\t";
    else
      cout<<i<<"\t";
  }
};
int main()
{
  graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.longest_path();
  return 0;
}
