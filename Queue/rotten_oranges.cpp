#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<queue>

using namespace std;

typedef struct ele
{
  int x,y;
}ele;
bool rot_orange(int arr[][c])
{
  queue<ele>q;
  ele temp;
  int ctr = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<4;j++)
      if(arr[i][j]==2)
        {
          temp.x = i;
          temp.y = j;
          q.push(temp);
        }
  temp.x = -1;
  temp.y = -1;
  q.push(temp);
  while(!q.empty())
  {
    bool flag = false;
    while(q.front().x!=-1 && q.front().y!=-1)
    {
      temp = q.front();

    }
  }
}
int main()
{
  int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};

  return 0;
}
