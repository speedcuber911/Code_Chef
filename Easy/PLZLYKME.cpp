#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long int l,d,s,c;
    cin>>l>>d>>s>>c;
    long long int likes=s;
    d--;
    while(d--)
    {
      if(likes>=l)
        break;
      else
        likes = likes*(1+c);
    }    
    if(likes>=l)
      cout<<"ALIVE AND KICKING\n";
    else
        cout<<"DEAD AND ROTTING\n";
  }
  return 0;
}
