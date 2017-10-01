#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<vector>

using namespace std;
class Graph{
public:
  int  v;
  list<int>*adj;
  Graph(int v)
  {
    this->v = v;
    adj = new list<int>[v];
  }
  void addEdge(int r,int s)
  {
    adj[r].push_back(s);
    adj[s].push_back(r);
  }
  bool bi_con();
  bool bi_con_util(int s,vector<bool> & vis,vector<int> & tym,vector<int> & low,vector<int> & par);
};
bool Graph::bi_con_util(int s,vector<bool> & vis,vector<int> & tym,vector<int> & low,vector<int> & par)
{
  vis[s]=1;
  static int time = 0;
  int child = 0;
  low[s]=tym[s]= ++time;
  auto it = adj[s].begin();
  for(it;it!=adj[s].end();++it)
  {
    int curr = *it;
    if(!vis[curr])
    {
        child++;
        par[curr] = s;
        if(bi_con_util(curr,vis,tym,low,par)==true)
          return true;
        low[*it] = min(low[*it],low[v]);
        if(par[*it]==-1 && child>1)
          return true;
        if(par[*it]!=-1 && low[v] >= tym[*it])
              return true;
    }
    else
      if(curr!=par[*it])
        low[*it] = min(low[*it],tym[curr]);
}
  return false;
}
bool Graph::bi_con()
{
  vector<bool>vis(v,0);
  vector<int>tym(v,0);
  vector<int>low(v,0);
  vector<int>par(v,-1);
  if(bi_con_util(0,vis,tym,low,par)==false)
    return false;
  for (int i = 0; i < v; i++)
       if (vis[i] == false)
         return false;
  return true;
}
int main()
{
  Graph g1(2);
   g1.addEdge(0, 1);
   g1.bi_con()? cout << "Yes\n" : cout << "No\n";
   return 0;
}
