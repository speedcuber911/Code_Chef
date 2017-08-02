#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

map<unsigned long int,unsigned long int>m;
unsigned long int max_am(unsigned long int n)
{
  if(n<=4)
    return n;
  if(m[n]>0)
    return m[n];
  else
  {    
    m[n]  max(n,(max_am(n/2)+max_am(n/3)+max_am(n/4)));
    return m[n];
  }
}
int main()
{

  unsigned long int n;
  while(cin>>n)
  {
    cout<<max_am(n)<<endl;
  }
  return 0;
}
