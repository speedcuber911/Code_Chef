#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;


// int maxl(vector<int>a)
// {
// int max_so_far = 0;
// int local_max = 0;
// for(int i=0;i<a.size()-1;i++)
// {
//   if(a[i+1]>a[i])
//     local_max++;
//   else
//   {
//     if(max_so_far<local_max)
//       max_so_far = local_max;
//     local_max = 0;
//   }
// }
// return max(local_max,max_so_far);
// }
int main()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  vector<int>lis(n,1);
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
    {
      if(a[i]>a[j])
        if(lis[i]<lis[j]+1)
          lis[i] = lis[j] + 1;
    }
int max = 0;
for (int i = 0; i < n; i++ )
   if (max < lis[i])
    max = lis[i];
  cout<<max<<endl;
  return 0;
}
