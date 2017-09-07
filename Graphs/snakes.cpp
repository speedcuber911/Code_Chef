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
    private:
        int v;
        list<int> * adj;
    public:
        Graph(int v);
        void addEdge(int v,int w);
        void bfs(int s);

};
Graph :: Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}
void Graph::addEdge(int v,int w)
{
      adj[v].push_back(w);
}
void GFrap::bfs:(int s)
{
    queue<int>q;
    q.push(s);
    vector<bool>visited(v);
    visited[s]=true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
//        visited[p]=true;
        list<int>::iterator it;
        cout<<p<<" ";
        it = adj[p].begin();
        for(it;it!=adj[p].end();++it)
        {
            if(visited[*it]==false)
            {

                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,m;
    while(t--)
    {
        map<int,int>ladder;
        map<int,int>snakes;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            ladder[a] = b;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            snakes[a] = b;
        }
        Graph g(101);
        for(int i=1;i<100;i++)
        {
                 for(int j=1;j<7;j++)
                 {
                   if(ladder[i]==0 && snakes[i]==0)
                       g.addEdge(i,i+j);
                 }
        }
        auto it = snakes.begin();
        for(it;it!=snakes.end();++it)
            g.addEdge(it->first,it->second);
        it = ladder.begin();
        for(it;it!=ladder.end();++it)
             g.addEdge(it->first,it->second);
        g.bfs(1);
    }
    return 0;
}
