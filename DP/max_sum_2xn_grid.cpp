#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<stack>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<vector<int> >arr(2,vector<int>(n,0));
  for(int i=0;i<n;i++)
  {
    cin>>arr[0][i];
    cin>>arr[1][i];
  }
  cout<<arr[0].size()<<" Size of row vector"<<endl;
  int temp;
  int excl = 0;
  int incl = max(arr[0][0],arr[1][0]);
  for(int i=1;i<n;i++)
  {
      temp = incl;
      incl = max(excl+max(arr[0][i],arr[1][i]),incl);
      excl = temp;
  }
  cout<<incl<<endl;
  return 0;
}
