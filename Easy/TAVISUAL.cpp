#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int update(int c,int a,int b)
{

  int ctr=0;
  while(a!=c)
  {
    ctr++;
    a++;
  }
  
  return(b-ctr);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,c,q;
    cin>>n>>c>>q;
    int pos=c;
    for(int i=0;i<q;i++)
    {
      int a,b;
      cin>>a>>b;
      if(pos>=a && pos<=b)
        {
          pos=update(pos,a,b);
        }
    }
    cout<<pos<<endl;
  }
  return 0;
}
