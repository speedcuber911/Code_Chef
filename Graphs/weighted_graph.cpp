#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<list>
using namespace std;

class Graph
{
  int v;
  list<int> * adj;
 public:
  Graph(int r)
  {
      this->v = r;
      adj = new list<int>[r];
  }
  void addEdge(int s,int t)
  {
      adj[s].push_back(t);
      adj[t].push_back(s);
  }
  bool place(vector<bool>vis)
  {
    for(int i=1;i<vis.size();i++)
      if(vis[i]==0)
        return true;
    return false;
  }
  int fetch(int &i_start, vector<bool>&vis,vector<int>weights)
  {
    int temp =-1;
    vis[i_start] =1;
    int connected_verts = 0;
    int max_weight =0;
    int indice;
    auto it  =adj[i_start].begin();
    for(it;it!=adj[i_start].end();++it)
    {
      if(!vis[*it])
      {
        connected_verts++;
        if(weights[*it-1] > max_weight)
          {
            max_weight = weights[*it-1];
            indice = *it;
          }
      }
    }
    vis[indice] = 1;
    i_start = indice;
    if(connected_verts==0)
      return -1;
    else
        {
          // cout<<max_weight<<" as max_weight "<<i_start<<" as next idice "<<endl;
          return max_weight;
        }
      }
  pair<int,int> process(int a_start,int b_start,vector<int>weights)
  {
      vector<bool>vis(v+1,0);
      vis[0]=1;
      vis[a_start]=1;
      vis[b_start]=1;
      int a_val = weights[a_start-1];
      int b_val = weights[b_start-1];
      bool a_possible = true;
      bool b_possible = true;
      int a_fetched=0,b_fetched=0;
      while(a_possible || b_possible)
      {
      if(a_possible)
      {
          a_fetched = fetch(a_start,vis,weights);
          if(a_fetched == -1)
              a_possible = false;
          else
              a_val += a_fetched;
      }
      //b's turn to move
      if(b_possible)
      {
          b_fetched = fetch(b_start,vis,weights);
          if(b_fetched == -1)
              b_possible = false;
          else
              b_val += b_fetched;
      }
      }
    //  cout<<a_val<<" :a's value "<<b_val<<" :b's value "<<endl;
     return make_pair(a_val,b_val);
  }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<int>weights;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        weights.push_back(t);
    }
    int x,y;
    Graph g = Graph(n+1);
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        g.addEdge(x,y);
    }
    // cout<<"No. of queries";
    int q;
    cin>>q;
    int wins_a=0,wins_b=0;
    int cumulative_a=0,cumulative_b=0;
    while(q--)
    {
        int a_start;
        int b_start;
        pair<int,int>vals;
        // cout<<"Start and end points\n";
        cin>>a_start>>b_start;
        vals = g.process(a_start,b_start,weights);
        if(vals.first > vals.second)
            wins_a++;
        else
            wins_b++;
        cumulative_a += vals.first;
        cumulative_b += vals.second;
    }
    cout<<wins_a<<" "<<cumulative_a<<" "<<wins_b<<" "<<cumulative_b<<endl;
    return 0;
}
