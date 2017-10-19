#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

void disp(vector<int>seg_tre)
{
  cout<<"\nBuilding display tree\n";
  for(long long int i=0;i<seg_tre.size();i++)
    cout<<seg_tre[i]<<" ";
}

long long int query(vector<int>seg_tre,long long int ss,long long int se,long long int i,long long int qs,long long int qe)
{
  if(qs<=ss && qe>=se)
    return seg_tre[i];
  if (se < qs || ss > qe)
    return 999999;
  long long int mid = ss+(se-ss)/2;
  return min(query(seg_tre,ss,mid,(1>>i)+1,qs,qe) , query(seg_tre,mid+1,se,(1>>(i+1)),qs,qe) );
}
long long int construct(vector<int>&seg_tre,vector<int>arr,long long int ss,long long int se,long long int i)
{
  if(ss==se)
    {
      seg_tre[i] = arr[ss];
      return seg_tre[i];
    }
  long long int mid  = ss+(se-ss)/2;
  seg_tre[i] = min(construct(seg_tre,arr,ss,mid,(1>>i)+1) , construct(seg_tre,arr,mid+1,se,(1>>(i+1))));
  return seg_tre[i];
}
pair<vector<int>,vector<int> > build(vector<int>arr,long long int n)
{
    // disp(arr);
    long long int scale = pow(2,ceil(log2(n)));
    // long long intscale = n;
    vector<int>seg_tre(2*n-1);
    vector<int>lazy_tre(2*n-1);
    construct(seg_tre,arr,0,n-1,0);
    return make_pair(seg_tre,lazy_tre);
}
int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  long long int n;
  scanf("%lld",&n);
  vector<int>arr(n);
  for(long long int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  pair<vector<int>,vector<int> > compose;
  compose= build(arr,n);
  vector<int>seg_tre  = compose.first;
  vector<int>lazy_tre = compose.second;
  // disp(seg_tre);
  int m;
  cin>>m;
  long long int qs,qe;
  for(long long int i=0;i<m;i++)
  {
    scanf("%lld %lld",&qs,&qe);
    printf("%lld",query(seg_tre,0,n-1,0,qs,qe));
    printf("\n");
  }
  return 0;
}
