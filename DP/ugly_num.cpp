#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void bt (vector<int>A)
{
  int i;
  int j;
  for(i=A.size()-1;i>=1;i--)
  if(A[i]>A[i-1])
  break;
  i-=1;
  if(i==0)
  sort(A.begin(),A.end());
  else
  {
    int j;
    for(j=A.size()-1;j>i;j++)
    if(A[j]>A[i])
    break;
    swap(A[i],A[j]);
    i++;
    int u = i;
    vector<int>v;
    for(i;i<A.size();i++)
      v.push_back(A[i]);
    int r=0;
    for(u;u<A.size();u++)
    {
      A[u] = v[r];
      r++;
    }
    for(int ufg=0;ufg!=A.size();ufg++)
      cout<<A[ufg];

  }
}

int main()
{
  vector<int>ug;
  int n=25;
  int i;
  while(n--)
  {
    cin>>i;
    ug.push_back(i);
  }
  bt(ug);
  return 0;

}
// 251 844 767 778 658 337 10 252 632 262 707 506 701 475 410 696 631 903 516 149 344 101 42 891 991
