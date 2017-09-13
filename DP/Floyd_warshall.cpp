#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

#define inf 9999999
using namespace std;

int floyd(int graph[][4])
{
  int dist[4][4]={0};
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
      dist[i][j] = graph[i][j];
    }
    for(int k=0;k<4;k++)
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(dist[i][j]>dist[i][k]+dist[k][j])
              dist[i][j] = dist[i][k]+dist[k][j];
        }
        for(int i=0;i<4;i++)
          {
            for(int j=0;j<4;j++)
            {
            if(dist[i][j]!=inf)
              cout<<dist[i][j]<<"  ";
            else
              cout<<"∞"<<"  ";
            }
            cout<<endl;
        }
        return 0;
}
int main()
{
  int graph[4][4] = {
                        {0,5,inf,10},
                        {inf,0,3,inf},
                        {inf,inf,0,1},
                        {inf,inf,inf,0}
                    };
   for(int i=0;i<4;i++)
     {
       for(int j=0;j<4;j++)
       {
       if(graph[i][j]!=inf)
         cout<<graph[i][j]<<"  ";
       else
         cout<<"∞"<<"  ";
       }
       cout<<endl;
   }
   floyd(graph);
  return 0;
}
