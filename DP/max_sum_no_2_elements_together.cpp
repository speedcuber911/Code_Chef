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
  vector<int>arr(n);
  for(int i=0;i<arr.size();i++)
    cin>>arr[i];
  int incl = arr[0];
  int excl = 0;
  int temp;
  for(int i=1;i<arr.size();i++)
  {
    temp = incl;
    incl = max(excl+arr[i],incl);
    excl = temp;
  }
  cout<<incl;
  return 0;
}
