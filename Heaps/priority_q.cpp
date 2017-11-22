#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

int sol(vector<int>B,int A)
{
  priority_queue<int>q;
    for(int i=0;i<B.size();i++)
        q.push(B[i]);
    long long int temp=0;
    long long int t;
    while(A--)
    {
      t = q.top();
      temp += q.top();
      q.pop();
      q.push(floor(t/2))                                ;
    }
    return temp%1000000007;
}

int sol_2(vector<int>a,int b)
{
vector<int>arr;
// if(B>A.size())
    // return arr;
// else
// {
    int j=0;
    for(int i=0;i<(a.size()-b+1);i++)
    {
          map<int,int>m;
          j = i;
          while(j<(b+i))
          {
            if(m[a[j]]==0)
              m[a[j]]=1;
            else
              m[a[j]]+=1;
            j++;
          }
        for(auto it= m.begin();it!=m.end();++it)
          {
            cout<<it->first<<"  "<<it->second<<endl;
          }
          // if(it->second==1)
          //   {
          //     cout<<"Inserting "<<it->first<<endl;
          //     arr.push_back(it->first);
          //   }
    }
// }
return 0;
}
int main()
{
  int n;
  cin>>n;
  int b;
  vector<int>A(n);
  for(int i=0;i<n;i++)
    cin>>A[i];
  cin>>b;
  sol_2(A,b);
  return 0;
}
