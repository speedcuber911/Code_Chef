#include <cstdio>
#include <vector>
#include<iostream>
#include<math.h>
#include<map>
#include<queue>

using namespace std;

void toarr(int digit[],int val)
{
  for(int i=0;i<4;i++)
    {
      digit[i] = val%10;
      val/=10;
    }
    swap(digit[0],digit[3]);
    swap(digit[1],digit[2]);
}
int todigit(int digit[])
{
  return(digit[0]*1000 + digit[1]*100 + digit[2]*10 + digit[3]);
}
void prime_up(vector<bool>&prim)
{
  for(int i=2;(i*i)<=prim.size();i++)
    if(prim[i]==true)
      for(int j=2*i;j<=prim.size();j+=i)
        prim[j]=false;
}
int main()
{
  int digit[4]={};
  vector<bool>prim(100000,1);
  prime_up(prim);
  int t;
  cin>>t;
  while(t--)
  {
    queue<int>q;
    vector<bool>vis(100000,0);
    vector<int>dist(100000,-1);
    int r,s;
    cin>>r>>s;
    if(r==s)
      cout<<0<<"\n";
    else
    {
      q.push(r);
      while(!q.empty())
      {
        int t = q.front();
        for(int i=0;i<4;i++)
          {
            toarr(digit,t);
            for(int j=0;j<10;j++)
              {
                  digit[i] = j;
                  int temp = todigit(digit);
                  if(!vis[temp] && prim[temp] && temp >=1000)
                  {
                    vis[temp] = true;
                    q.push(temp);
                    dist[temp] = dist[t] + 1;
                  }
              }
          }
          q.pop();
      }
      if(dist[s]==-1)
        cout<<"-1\n";
      else
        cout<<dist[s]<<"\n";
    }
  }
  return 0;
}
