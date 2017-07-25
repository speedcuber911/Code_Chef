#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>

using namespace std;

float dist(int x,int y,int z, int w)
{
  cout<<"visiting "<<x<<","<<z<<"---> "<<y<<","<<w<<endl;
  return sqrt(float((x-y)*(x-y)+(z-w)*(z-w)));
}
void sort(vector<int> &x,vector<int> &y)
{
  int temp;
  for(int i=0;i<x.size();i++)
    for(int j=0;j<x.size()-1-i;j++)
      {
        if(x[j]>x[j+1])
          {
            temp = x[j];
            x[j] = x[j+1];
            x[j+1] = temp;
            temp = y[j];
            y[j] = y[j+1];
            y[j+1] = temp;
          }
      }
}
bool in(int a,vector<int>map)
{
  bool flip=0;
  for(int i=0;i<map.size();i++)
    if(map[i]==a)
      flip=1;
  return flip;
}
int main()
{
  int t,n;
  cin>>t;
  cout<<setprecision(2)<<fixed;
  while(t--)
  {
    float distance = 0;
    vector<int>map;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i<n;i++)
      {
        cin>>x[i];
        cin>>y[i];
      }
      sort(x,y);
    for(int i=0;i<x.size()-1;i++)
    {
        if(x[i]!=x[i+1] && !in(i,map))
          distance+=dist(x[i],x[i+1],y[i],y[i+1]);
        else
            {
                int a = i+1,pos=i,large=y[i];
                for(;a<x.size();a++)
                  {
                    if(y[a]>large)
                      pos=a;
                  }
                  if(pos!=0)
                    map.push_back(pos);
                  distance+= dist(x[a],x[i+1],y[a],y[i+1]);
            }
    }
    cout<<distance<<endl;
  }
  return 0;

}
