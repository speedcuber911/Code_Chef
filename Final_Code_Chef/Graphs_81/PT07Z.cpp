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

int bfs(vector<int>&vis,int src,bool param,list<int> * adj)
{
  vis[src] = 0;
  queue<int>q;
  q.push(src);
  while(!q.empty())
  {
    int top =  q.front();
    q.pop();
    for(auto it= adj[top].begin();it!=adj[top].end();++it)
    {
      if(vis[*it]==-1)
        {
          q.push(*it);
          vis[*it] = vis[top] + 1;
        }
    }
  }
  int maxer=0;
  int pos;
  for(int i=1;i<vis.size();i++)
    {
      if(vis[i]>maxer)
      {
        maxer = vis[i];
        pos = i;
      }
      vis[i]=-1;
    }
  if(!param)
      return pos;
  else
    return maxer;
}
int main()
{
  int v;
  cin>>v;
  v++;//zero indexing
  list<int> * adj = new list<int>[v];
  int x,y;
  for(int i=1;i<v-1;i++)
    {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<int>vis(v,-1);
    cout<<bfs(vis,(bfs(vis,1,0,adj)),1,adj);
  return 0;
}
