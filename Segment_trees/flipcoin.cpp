#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int build_seg(vector<int>&seg_tre,vector<int>arr,int ss,int se,int i)
{
  if (se == ss)
     {
        cout<<"Inserting "<<arr[ss]<<" at "<<i<<endl;
         seg_tre[i] = arr[ss];
         return arr[ss];
     }
     int mid = (ss+se)/2;
     seg_tre[i] =  build_seg(seg_tre,arr, ss, mid,i*2+1) + build_seg(seg_tre,arr, mid+1, se, i*2+2);
     return seg_tre[i];
}
int recur_query(int qs,int qe,int ss,int se,vector<int> &seg_tree,int i)
{
  if(qs <= ss && qe >= se)// 1,3
        return seg_tree[i];
  if(ss > qe || se < qs)
    return 0;
  int mid = (ss+se)/2;
  return recur_query(qs,qe,ss,mid,seg_tree,2*i+1) + recur_query(qs,qe,mid+1,se,seg_tree,2*(i+1));
}
int query(int u,int v,vector<int>seg_tree,int scale)
{
  if(u < 0 || v > seg_tree.size()-1 || u > v)
    return -1;
  else
      return recur_query(u,v,0,scale-1,seg_tree,0);
}
int update(int diff,vector<int>&seg_tre,int ss,int se,int u,int v,int si)
{
  if(ss > se || ss > v || se < u)
    return seg_tre[si];
  if(ss == se)//Which we know by now, is tyhe condition for leaf nodes
  {
    seg_tre[si]+=diff;
    return seg_tre[si];
  }
  int mid = (ss+se)/2;
    seg_tre[si] = ( update(diff,seg_tre,ss,mid,u,v,2*si+1) + update(diff,seg_tre,mid+1,se,u,v,2*(si+1)));
    return seg_tre[si];
}
void disp(vector<int> seg_tre)
{
  cout<<"\nPrinting segment tree\n";
  for(int i=0;i<seg_tre.size();i++)
    cout<<seg_tre[i]<<" ";
}
int main()// Yeah, I can build a segment tree now, its functional perfectly, slight doubts in mind, about how its working
// Thats probably because of the fact that i am bad at recursion!
{
  int n;
  cin>>n;
  long int  scale = pow(2,ceil(log2(n)));
  vector<int>arr(scale,0);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<scale<<" is the size\n";
  vector<int>seg_tre(2*scale-1,0);
  build_seg(seg_tre,arr,0,scale-1,0);
  disp(seg_tre);
  cout<<"enter range\n";
  int u,v,diff;
  cin>>u>>v;
  cout<<"Enter difference\n";
  cin>>diff;
  update(diff,seg_tre,0,scale-1,u-1,v-1,0);
  disp(seg_tre);
  return 0;
}
