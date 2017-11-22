#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#define r 4
#define c 4

using namespace std;

bool invalid(int i,int j)
{
  if(i==r || i<0 || j==c || j<0)
    return true;
  return false;
}
int ways(int m[][c],int i,int j)
{
  if(m[0][0] == -1)
    return 0;
  if(invalid(i,j))
    {
    cout<<"Invalid for "<<i<<"  "<<j<<endl;
    return 0;
    }
  else
  {
    if(m[i][j]== -1 && i!=0 && j!=0)
      return 0;
    if(i==r-1 && j==c-1)
      return 1;
  }
  return (ways(m,i+1,j) + ways(m,i-1,j) + ways(m,i,j-1) + ways(m,i,j+1));
}
int main()
{
  int maze[r][c] =  {{0,  0, 0, 0},
                      {0, -1, 0, 0},
                      {-1, 0, 0, 0},
                      {0,  0, 0, 0}};
  cout<<ways(maze,0,0)<<endl;
  return 0;
}
