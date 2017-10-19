#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

typedef struct edge
{
int src,dest,weight;
}edge;
class graph
{
    int v,e;
    edge *eg;
  public:
    graph(int r,int s)
    {
      this->v = r+1;
      this->e = s;
      eg = new edge[e];
    }
    void addEdge(int j,int i,int w,int edge)
    {
      this->eg[edge].src = j;
      this->eg[edge].dest = i;
      this->eg[edge].weight = w;
    }
    void bellman_ford(int src)
    {
      vector<int>dist(v,INT_MAX);
      dist[src]=0;
      for(int i=1;i<=v;i++)
      {
        for(int j=0;j<e;j++)
          {
          if(dist[eg[j].src] != INT_MAX && (dist[eg[j].src] + eg[j].weight) <  dist[eg[j].dest])
              dist[eg[j].dest] = dist[eg[j].src] + eg[j].weight;
          }
      }
      for(int j=0;j<e;j++)
        {
          if(dist[eg[j].src] != INT_MAX && (dist[eg[j].src] + eg[j].weight) <  dist[eg[j].dest])
            cout<<"Graph has a negative weight cycle\n";
        }
      for(int i=1;i<v;i++)
        cout<<i<<"\t"<<dist[i]<<endl;
    }
};
int main()
{
  graph g = graph(5,8);
  g.addEdge(1,3,1,0);
  g.addEdge(1,2,-1,1);
  g.addEdge(2,5,2,2);
  g.addEdge(2,4,2,3);
  g.addEdge(2,3,3,4);
  g.addEdge(4,2,1,5);
  g.addEdge(4,3,5,6);
  g.addEdge(5,4,-3,7);
  g.bellman_ford(1);
  return 0;
}
