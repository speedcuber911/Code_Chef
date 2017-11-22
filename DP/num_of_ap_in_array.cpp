#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>

using namespace std;

// int numofAP(int arr[],int n)
// {
//   int mini = INT_MAX;
//   int maxi = INT_MIN;
//   for(int i=0;i<n;i++)
//   {
//     mini = min(mini,arr[i]);
//     maxi = max(maxi,arr[i]);
//   }
//   vector<int>dp(n);
//   vector<int>sum(maxi);
//   int total = n+1;//Factoring in individuals and 1 empty one
//   for(int i = (mini-maxi);i<=(maxi-min);i++)
//   {
//       memset(sum,0,maxi);
//       for(int i=0;i<n;i++)
//         {
//           dp[i] =1;
//           if((arr[i]-d)>=1)
//             dp[i] += sum[arr[i]-d];
//           ans += dp[i] -1;
//           sum[arr[i]] += dp[i];
//          }
//   }
// }
// int main()
// {
//   int arr[] = { 1, 2, 3 };
//   int n = sizeof(arr)/sizeof(arr[0]);
//   cout << numofAP(arr, n) << endl;
//   return 0;
// }
bool decreasing(vector<int>r,bool det)
{
  if(det)
    reverse(r.begin(),r.end());
  if(r.size()==1 || r.size()==0)
    return true;
  int dyn_max = r[0];
  for(int i=1;i<r.size();i++)
    {
      if(r[i]>dyn_max)
        return false;
      else
        dyn_max = min(dyn_max,r[i]);
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
    int n,dir;
    cin>>n>>dir;
    vector<int>arr(n);
    vector<int>left_gs;
    vector<int>right_gs;
    for(int i=0;i<n;i++)
      {
        cin>>arr[i];
        if(arr[i]>dir && arr[i]!=dir)
          left_gs.push_back(arr[i]);
        if(arr[i]<dir && arr[i]!=dir)
          right_gs.push_back(arr[i]);
      }
    if(!decreasing(left_gs,0) || !decreasing(right_gs,1))
      cout<<"NO\n";
    else
      cout<<"YES\n";
  }
  return 0;
}