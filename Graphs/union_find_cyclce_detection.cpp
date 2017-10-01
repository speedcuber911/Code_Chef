#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<list>
#include<queue>

using namespace std;

vector<int>parent,sizer;
int root(int x)
{
  while(parent[x]!=x)
  {
    parent[x]=parent[parent[x]];
    x=parent[x];
  }
  return x;
}
bool find(int x,int y)
{
  if(root(x)==root(y))
    return true;
  else
    return false;
}
void _union(int x,int y)
{
  int rootx = root(x);
  int rooty = root(y);
  if(sizer[rootx]<sizer[rooty])
  {
    parent[rootx] = parent[rooty];
    sizer[rooty] += sizer[rootx];
  }
  else
  {
    parent[rooty] = parent[rootx];
    sizer[rootx] += sizer[rooty];
  }
}
int main()
{
  int n,e;
  // n++;
  cin>>n>>e;
  n++;
  parent.resize(n);
  sizer.resize(n);
  for(int i=0;i<n;i++)
  {
      parent[i] = i;
      sizer[i] = 0;
  }
  bool flag = false;
  int x,y;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    if(find(x,y))
      flag=true;
    else
      _union(x,y);
  }
  flag?cout<<"cycle\n":cout<<"NOT cyclcil";
  return 0;
}
