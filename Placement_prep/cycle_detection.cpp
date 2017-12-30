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
  bool cyclic(vector<bool>&vis,vector<bool>&rec,int i)
  {
    if(!vis[i])
    {
      vis[i] = true;
      rec[i] = true;
      for(auto it=adj[i].begin();it!=adj[i].end();++it)
      {
        if(!vis[*it] && cyclic(vis,rec,*it))
          return true;
        else
          if(rec[*it])
            return true;
      }
    }
    rec[i] = false;
    return false;
  }
  bool _cycle()
  {
    vector<bool>vis(v,0),rec(v,0);
    for(int i=0;i<v;i++)
      if(cyclic(vis,rec,i))
        return true;
    return false;
  }
};

int main()
{
  graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    if(g._cycle())
      cout<<"Cyclic\n";
    else
        cout<<"No cycle\n";
  return 0;
}
