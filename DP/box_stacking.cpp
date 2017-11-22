#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

typedef struct box{
  int h,w,d;
}box;
bool comp(const box a,const box b)
{
  if( (a.w*a.d) - (b.w*b.d) >0)
    return true;
  return false;
}
int main()
{
    int n;
    cin>>n;
    //L  B   H
    vector<box>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].h>>arr[i].w>>arr[i].d;
    box t;
    for(int i=0;i<n;i++)
    {
      t = arr[i];
      swap(t.h,t.w);
      arr.push_back(t);
      t = arr[i];
      swap(t.h,t.d);
      arr.push_back(t);
    }
    sort(arr.begin(),arr.end(),comp);
    cout<<endl;
    for(int i=0;i<3*n;i++)
      cout<<arr[i].h<<" "<<arr[i].w<<" "<<arr[i].d<<endl;
    vector<int>m(3*n);
    for(int i=0;i<3*n;i++)
      m[i] = arr[i].h;
    for(int i=1;i<3*n;i++)
      for(int j=0;j<i;j++)
        {
          if(arr[i].w < arr[j].w && arr[i].d < arr[j].d)
            if(m[i] < m[j] + arr[i].h)
              m[i] = m[j] + arr[i].h;
        }
    int maxi = INT_MIN;
    for(int i=0;i<m.size();i++)
      maxi = max(maxi,m[i]);
    cout<<maxi<<endl;
    return 0;
}
