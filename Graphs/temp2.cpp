#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

int count(int n)
{
    // table[i] will store count of solutions for
    // value i.
    int table[n+1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (i=3; i<=n; i++)
       table[i] += table[i-3];
    for (i=5; i<=n; i++)
       table[i] += table[i-5];
    for (i=10; i<=n; i++)
       table[i] += table[i-10];

    for(int i=0;i<=n;i++)
      {
        cout<<i<<":"<<table[i]<<endl;
      }
      cout<<table[n];
      return table[n];
}

int main()
{
  int n;
  cin>>n;
  count(n);
  return 0;
}
