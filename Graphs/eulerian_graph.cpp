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
    adj[v].push_back(u);
  }
  void DFS_util(vector<bool>&vis,int src)
  {
    vis[src]=1;
    auto it = adj[src].begin();
    for(it;it!=adj[src].end();++it)
    {
      if(!vis[*it])
        DFS_util(vis,*it);
    }
  }
  bool Connected()
  {
    //Check if a graph has no edges
    vector<bool>vis(v,0);
    int i;
    for(i=0;i<v;i++)
      if(adj[i].size()!=0)
        break;
    if(i==v)
      return true;
    DFS_util(vis,i);//DFS for the first vertex, which does not have zero degree
    for(i=0;i<v;i++)
      if(vis[i]==false && adj[i].size()>0)//All non zero degree vertices visited
        return false;
    return true;
  }
  int eulerian()
  {
    if(Connected()==false)
      return false;
    int odd_vertices = 0;
    for(int i=0;i<v;i++)
      if(adj[i].size() & 1)// A cooler way to check for odd value;
        odd_vertices++;
    if(odd_vertices>2)
          return 0;//Not eulerian
    if(odd_vertices==2)
      return 1;//Semi Eulerian
    if(odd_vertices==0)
      return 2;//Eulerian
  }
  void test()
  {
    int val = eulerian();
    if(val==0)
      cout<<"Not Eulerian\n";//Does not have a eulerian trail
    if(val==1)
      cout<<"Semi Eulerian\n";//Does not have a cycle but has a path
    if(val==2)
      cout<<"Eulerian\n";//Does have a cycle
  }
};
int main()//Only check in an undirected graphs
{
  Graph g1(5);
   g1.addEdge(1, 0);
   g1.addEdge(0, 2);
   g1.addEdge(2, 1);
   g1.addEdge(0, 3);
   g1.addEdge(3, 4);
   g1.test();
   Graph g2(5);
   g2.addEdge(1, 0);
   g2.addEdge(0, 2);
   g2.addEdge(2, 1);
   g2.addEdge(0, 3);
   g2.addEdge(3, 4);
   g2.addEdge(4, 0);
   g2.test();
   Graph g3(5);
   g3.addEdge(1, 0);
   g3.addEdge(0, 2);
   g3.addEdge(2, 1);
   g3.addEdge(0, 3);
   g3.addEdge(3, 4);
   g3.addEdge(1, 3);
   g3.test();
   Graph g4(3);
   g4.addEdge(0, 1);
   g4.addEdge(1, 2);
   g4.addEdge(2, 0);
   g4.test();
   Graph g5(3);
   g5.test();
  return 0;
}
