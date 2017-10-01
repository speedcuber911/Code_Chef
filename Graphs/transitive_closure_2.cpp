#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

class Graph{
    public:
    int v;
    list<int>*adj;
    bool **tc;
    Graph(int t)
    {

        this->v = t;
        adj = new list<int>[t];
        tc = new bool* [v];
        for(int i=0;i<v;i++)
            tc[i] = new bool[v];
    }
   void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    void DFS(int s,int v)
    {
        tc[s][v] = true;
        auto it = adj[s].begin();
        for(it;it!=adj[s].end();++it)
        {
            if(tc[s][*it]==false)
                DFS(s,(*it));
        }
    }
    void t_closure()
    {
        for(int i=0;i<v;i++)
            DFS(i,i);
    }
};
int main()
{
    int N, I;
    cin >> N >> I;
    Graph g = Graph(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a,b);
    }
    g.t_closure();
    long long result = 0;
    vector<long int >sum_up;
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        cout<<g.tc[i][j]<<" ";
      cout<<endl;
    }

    for(int i=0;i<N;i++)
    {   int s=0;
        for(int j=0;j<N;j++)
        {
          if(g.tc[i][j]==1)
          s++;
        }
        // cout<<s<<" ";
        sum_up.push_back(s);
     }
     cout<<endl;
    for(int i=0;i<sum_up.size();i++)
        for(int j=i+1;j<sum_up.size();j++)
                result+= sum_up[i]*sum_up[j];
    cout << result<< endl;
    return 0;
}
