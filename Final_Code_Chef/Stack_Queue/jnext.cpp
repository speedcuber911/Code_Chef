#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

template <typename T>
bool nextPermutation(vector<T> &vec) {
	if (vec.empty())
		return false;
	auto i = vec.end() - 1;
	while (i > vec.begin() && *(i - 1) >= *i)
		--i;
	if (i == vec.begin())
		return false;
	auto j = vec.end() - 1;
	while (*j <= *(i - 1))
		--j;
	iter_swap(i - 1, j);
	reverse(i, vec.end());
	return true;
}

bool _perf(vector<int>&ar)
{
  if (ar.empty())
    return false;
  int i,j;
  for(i=ar.size()-2;i>=0;i--)
    if(ar[i]<ar[i+1])
        break;
  // cout<<i<<"this is I";
  for(j=ar.size()-1;j>=0;j--)
    if(ar[j]>ar[i])
      break;
  if(i==-1)
    return false;
  else
  {
    swap(ar[i],ar[j]);
    reverse(ar.begin()+i+1,ar.end());
  }
  return true;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
  int n;
  cin>>n;
  vector<int>ar(n);
  for(int i=0;i<n;i++)
      cin>>ar[i];
  if(_perf(ar))
    for(int i=0;i<ar.size();i++)
      cout<<ar[i];
  else
      cout<<-1;
  cout<<endl;
}
return 0;
}
