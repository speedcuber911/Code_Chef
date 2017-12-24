#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>

using namespace std;

void printer(vector<int>u)
{
  cout<<"This------>\t";
  for(int i=0;i<u.size();i++)
    cout<<u[i]<<" ";
  cout<<endl;
}
void genSubsets(vector<int>&A,int start,vector<int> &ans,vector<vector<int> >&res)
{
  res.push_back(ans);
  printer(ans);
  for (int i=start; i<A.size();i++)
  {
    if(A[i] == A[i-1] && (i>start))
      continue;
    ans.push_back(A[i]);
    genSubsets(A,i+ 1,ans,res);
    ans.pop_back();
  }
}

int main()
{
    vector<int>A(3);
    A[0] = 1;
    A[1] = 2;
    A[2] = 2;
    // A[3] = 4;
    vector<vector<int> >res;
    vector<int>ans;
    sort(A.begin(),A.end());
    genSubsets(A,0,ans,res);
    // return res;
  return 0;
}
