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

void compute_lis(vector<int>&lis,vector<int>arr)//Hmm, does make sense,
{
  for(int i=1;i<arr.size();i++)
    for(int j=0;j<i;j++)
      if(arr[j]<arr[i] && (lis[j]+1) > lis[i])
        lis[i] = lis[j] + 1;
}
void compute_lds(vector<int>&lds,vector<int>arr)
{
    for(int i=arr.size()-2;i>=0;i--)
      for(int j=arr.size()-1;j>i;j--)
      {
        if(arr[i] > arr[j] && lds[i] < lds[j] + 1)
          lds[i] = lds[j] +1;
      }
}
int main()
{
  int n;
  cin>>n;
  vector<int> ar(n);
  for(int i=0;i<n;i++)
    cin>>ar[i];
  vector<int>lis(n,1);
  vector<int>lds(n,1);
  compute_lis(lis,ar);
  compute_lds(lds,ar);
  // cout<<"Largest increasing subsequence\n";
  reverse(lds.begin(),lds.end());
  int mi =-1;
  int max = 0;
  for(int i=0;i<lis.size();i++)
    {
      if((lis[i]+lds[i])>max)
        {
          max = lis[i]+lds[i];
          mi = i;
        }
    }
  cout<<max-1<<endl;  
  return 0;
}
