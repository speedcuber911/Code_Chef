#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int find_paths(int maze[][4],int i,int j)
{
  if(i>=3 && j>=3)
    return 1;
  if(maze[i+1][j]==-1 && maze[i][j+1]==-1)
    return 0;
    if(maze[i+1][j]==-1)
    return find_paths(maze,i,j+1);
    if(maze[i][j+1]==-1)
    return find_paths(maze,i+1,j);
  if(i==3)
    return find_paths(maze,i,j+1);
    if(j==3)
      return find_paths(maze,i+1,j);
    return (find_paths(maze,i+1,j)   +  find_paths(maze,i,j+1));
}
int main()
{
  int maze[4][4] =  {
                {0,0,0,0},
                {0,-1,0,0},
                {-1,0,0,0},
                {0,0,0,0}
  };

  cout<<find_paths(maze,0,0)<<endl;
  return 0;
}
