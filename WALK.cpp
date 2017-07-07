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
    long int n,input;
    cin>>n;
    long int big2=-1;
    for(int i=0;i<n;i++)
    {
      cin>>input;
      if(big2>input+i)
        big2=big2;
      else
        big2 = input+i;
    }
    cout<<big2<<endl;
  }
  }
