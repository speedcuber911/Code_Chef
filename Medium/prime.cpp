#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>

using namespace std;
int pr[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

bool div(int a)
{
  for(int i=0;i<25;i++)
    if(a%pr[i]==0)
      return 0;
  return 1;
}
bool isprim(int a)
{
  for(int i=2;i<=sqrt(a)+1;i++)
    if(a%i==0)
      return 0;
  return 1;
}
int main()
{
  int t;
  cin>>t;
  unsigned long int n,m;
  while(t--)
  {
    cin>>m>>n;
    if(m>100)
    for(unsigned long int i=m;i<=n;i++)
    {
      if(div(i))
        if(isprim(i))
          cout<<i<<endl;
    }
    else
    {
      int i=0;
      while(pr[i]<m)
        i++;
      while(pr[i]<=n)
        {
          cout<<pr[i]<<endl;
          i++;
        }
    }
  }

  return 0;
}
