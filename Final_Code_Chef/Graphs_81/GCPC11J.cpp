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
// #include<bits/stdc++.h>
using namespace std;

class Graph{

  int v;
  list<int>* adj;
public:
  Graph(int r)
  {
    this->v = r;
    adj = new list<int>[r];
  }
  void addEdge(int x,int y)
  {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  pair<int,int> bfs(int src)
  {
    vector<int>dis(v,-1);
    queue<int>q;
    q.push(src);
    dis[src]=0;
    while(!q.empty())
    {
      int r = q.front();
      q.pop();
      for(list<int>::iterator it = adj[r].begin();it!=adj[r].end();++it)
        {
            if(dis[*it]==-1)
            {
              q.push(*it);
              dis[*it] = dis[r]+1;
            }
        }
    }
    int max_d = 0;
    int far_node;
    for(int i=0;i<dis.size();i++)
      if(dis[i]>max_d)
        {
          max_d = dis[i];
          far_node = i;
        }
      return make_pair(far_node,max_d);
  }
  int longest()
  {
    pair<int,int>n1,n2;
    n1 = bfs(0);// Gives the farthes end from one point
    //n1 first has the farthest node and n1 second has the distance to farthest node
    n2 = bfs(n1.first);// Takes you from the farthest point to another end point
    if(n2.second==1)
      return 1;
    else
      return (n2.second%2==0)?(n2.second/2):(n2.second/2+1);
  }
};
int  main()//BFS to find the longest path in the graph
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    Graph g = Graph(n);
    int e=n-1;
    int x,y;
    for(int i=0;i<e;i++)
    {
      cin>>x>>y;
      g.addEdge(x,y);
    }
    cout<<g.longest()<<"\n";
  }
  return 0;
}
