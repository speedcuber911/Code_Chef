#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

bool isprime(int x)
{
  int i;
  for(i=2;i<x;i++)
    if(x%i==0)
      break;
  if(i==x)
    return 1;
  else
    return 0;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int x,y;
    cin>>x>>y;
    int i=x+y;
    int temp = i;
    i++;
    while(1)
    {
        if(isprime(i))
          {
            cout<<i-temp<<endl;
            break;
          }
        else
          i++;

    }

  }
  return 0;
}
