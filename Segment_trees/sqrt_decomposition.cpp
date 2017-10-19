#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int update(vector<int>&block,vector<int>&arr,int index,int val)
{
  int scale = sqrt(arr.size());
  block[index/scale] += val - arr[index];
  arr[index] = val;
}
int query(int qs,int qe,vector<int>arr,vector<int>block)
{
  int sum =0;
  int scale = sqrt(arr.size());
  while(qs < qe && qs%scale!=0 && qs!=0)//Till the end of first complete block
    {
      sum += arr[qs];
      qs++;
    }
  while(qs + scale <=qe)//
  {
    sum += block[qs/scale];
    qs += scale;
  }
  while(qs<=qe)
  {
    sum+=arr[qs];
    qs++;
  }
return sum;
}
int _process(vector<int>arr,vector<int>&block)
{
  int block_size = sqrt(arr.size());
  int block_index = -1;
  for(int i=0;i<arr.size();i++)
  {
    if(i%block_size ==0)
      block_index++;
    block[block_index]  += arr[i];
  }
  return block_size;
}
int main()// Breaking the array into square root no. of
{
  int n;
  cin>>n;
  vector<int>arr(n,0);
  vector<int>block(ceil(sqrt(n)));
  for(int i=0;i<n;i++)
    cin>>arr[i];
  // cout<<sqrt(10)<<endl;
  int block_size = _process(arr,block);
  for(int i=0;i<block.size();i++)
      cout<<block[i]<<" ";
  int u,v;
  cout<<"Query range: ";
  cin>>u>>v;
  cout<<query(u-1,v-1,arr,block);
  cout<<endl;
  return 0;
}
