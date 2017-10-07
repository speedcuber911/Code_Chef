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

int ROW;
int COL;
bool isbound(int r, int t)
{
  return( (r>=0 && r<ROW) && (t>=0 && t< COL) );
}
int max_p(string mat[ROW],vector<vector<int> >&vis,int r,int s)
{
  if(!isbound(r,s) || mat[r][s]!='#')
    return 0;
  if(vis[r][s]!=0)
    return vis[r][s];
  else
      return max (  1+max_p(mat,vis,r,s-1) , max (   1+max_p(mat,vis,r-1,s) ,max(1 + max_p(mat,vis,r,s+1) , 1 + max_p(mat,vis,r+1,s) ) )  )  ;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>ROW>>COL;
    string  mat [ROW];
    vector<vector<int> >vis (ROW , vector<int> (COL,0) );
    char temp;
    for(int i=0;i<ROW;i++)
      for(int j=0;j<COL;j++)
      {
          cin>>temp;
          mat[i] += temp;
          vis[i][j]=0;
      }
      int maxer = 0;
      for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            if(mat[i][j]=='.')
              {
                  maxer = max(maxer,max_p(mat,vis,i,j));
              }
        cout<<maxer;      
  }
  return 0;
}
