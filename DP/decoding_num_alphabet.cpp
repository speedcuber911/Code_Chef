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

int main()// Not complete !
{
  string a;
  cin>>a;
  int n = a.size();
  vector<int>count(a.size()+1,0);
  count[0] =1;
  count[1] =1;
  for(int i=2;i<=n;i++)
  {
    if(a[i-1]>'0')
        count[i] = count[i-1];
    if( (a[i-2] == '1' || a[i-2] == '2') && a[i-1] <'7')
        count[i] +=count[i-2];
  }
  cout<<count[n]<<endl;
  return 0;
}
