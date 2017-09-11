#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
int _sum_up(int * seg_tree,int lb,int rb,int start,int end,int i)
{
  if(start<=lb && end>=rb)
      return seg_tree[i];
  if(start > rb || end < lb)
    return 0;
  else
  {
    int mid  = (lb+rb)/2;
    return _sum_up(seg_tree,lb,mid,start,end,2*i+1) + _sum_up(seg_tree,mid+1,rb,start,end,2*i+2);
  }
}
int construct_st_util(int arr[],int ss,int se,int *seg_tree,int si)
{
  if(ss == se)
    {
      seg_tree[si] = arr[ss];
      return arr[ss];
    }
  int mid = (ss+se)/2;
  seg_tree[si]  = construct_st_util(arr,ss,mid,seg_tree,si*2+1) +  construct_st_util(arr,mid+1,se,seg_tree,si*2+2);
  return seg_tree[si];
}
int * construct_st(int arr[],int n)
{
  int height = (int)ceil(log2(n));
  int max_size  = 2*pow(2,height)-1;//Size of the made array(seg tree)
  int *seg_tree = new int[max_size];
  construct_st_util(arr,0,n-1,seg_tree,0);
  return seg_tree;
}
int main()
{
  int arr[] = {1,3,5,7,9,11};
  int *seg_tree = construct_st(arr,6);
  cout<<_sum_up(seg_tree,0,15,1,3,0);
  return 0;
}
