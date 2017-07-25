#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  unsigned long long int a;
  unsigned long long int b;
  cin>>a;
  b=a%6;
  if(b==0 || b==1 || b==3)
    cout<<"yes";
  else
    cout<<"no";
  return 0;
}
