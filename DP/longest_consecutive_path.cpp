#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;

bool isbounded(int a,int b,int n)
{
  if(a<0 || b<0 || a>=n || b>=n)
    return false;
  return true;
}

int dfs_util(char arr[3][3],int n,int begx,int begy,int &length,int vis[3][3])
{
  cout<<"Moved to index "<<arr[begx][begy]<<endl;
  length +=1;
  int xs[] = {-1,-1,-1,0, 0, 1,1,1};
  int ys[] = {-1, 0, 1,1,-1,-1,0,1};
  for(int i=0;i<8;i++)
  {
    if( isbounded(begx+xs[i],begy+ys[i],n) && vis[begx+xs[i]][begy+ys[i]]==0 && arr[begx+xs[i]][begy+ys[i]] == (1 + arr[begx][begy]) )
      {
        vis[begx+xs[i]][begy+ys[i]] = 1;
        dfs_util(arr,n,begx+xs[i],begy+ys[i],length,vis);
      }
  }
  return length;
}
int dfs(char arr[3][3],int n,char ch)
{
  int vis[3][3] ={0};
  int length = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(arr[i][j] == ch)
        {
          length = 0;
          dfs_util(arr,n,0,0,length,vis);
          cout<<length<<endl;
        }
  return length;
}
int main()
{
  char arr[3][3] = { {'a','c','d'},
                   { 'h','b','a'},
                   { 'i','g','f'}};
  cout<<dfs(arr,3,'a');
  return 0;
}
