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

bool bounded(vector<vector<int> >mat, int i ,int j, vector<vector<bool> >vis,int bound)
{
    return ( (i>=0 && i<bound) && (j>=0 && j<bound) && (mat[i][j]!=0 && vis[i][j]==0));
}
void DFS(vector<vector<int> >mat,int i,int j,vector<vector<bool> >&vis)
{
  static int row_rule[] = {-1,-1,-1,0,0,1,1,1};
  static int col_rule[] = {-1,0,1,-1,1,-1,0,1};
  vis[i][j] = true;
  for(int r=0;r<8;r++)
    if(bounded(mat,i+row_rule[r],j+col_rule[r],vis,mat[0].size()))
      DFS(mat,i+row_rule[r],j+col_rule[r],vis);
}
int count_islands(vector<vector<int> >mat,int n)
{
  vector<vector<bool> >vis(n, vector<bool>(n,false));
  int ctr=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      if(mat[i][j]==1 && vis[i][j]==false)
        {
        DFS(mat,i,j,vis);
        ctr++;
        }
    }
  return ctr;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int> >mat(n,vector<int>(n));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
        cin>>mat[i][j];
  }
  cout<<"\n"<<count_islands(mat,n)<<endl;
  return 0;
}
