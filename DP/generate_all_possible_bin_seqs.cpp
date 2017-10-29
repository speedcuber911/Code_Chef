#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int siz = pow(2,n);
  for(int i=0;i<siz;i++)
    {
      for(int j=0;j<n;j++)
        if(i & (1<<j))
          cout<<1;
        else
          cout<<0;
      cout<<endl;
      }
  return 0;
}
