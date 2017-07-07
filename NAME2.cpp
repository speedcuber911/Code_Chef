// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<string>
// #include<map>
// #include<math.h>
//
// using namespace std;
//
// bool issubseq(string a ,string b,int m ,int n)
// {
//   if(m==0)
//     return 1;
//   if(n==0)
//     return 0;
//   if(a[m-1]==b[n-1])
//     return(issubseq(a,b,m-1,n-1));
//   return(issubseq(a,b,m,n-1));
// }
// int main()
// {
//   int t;
//   cin>>t;
//   while(t--)
//   {
//     string a,b;
//     cin>>a>>b;
//     int m = a.length();
//     int n = b.length();
//     if(n>m)
//     {
//       if(issubseq(a,b,m,n))
//         cout<<"YES\n";
//         else
//         cout<<"NO\n";
//     }
//     else
//     {
//        if(issubseq(b,a,n,m))
//         cout<<"YES\n";
//        else
//         cout<<"NO\n";
//       }
//   }
//   return 0;
// }
//


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    map<int,int>dict;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      {
        cin>>a[i];
        dict[a[i]]=1;
      }
    map<int,int>::iterator it;
    int count=0;
    for(it=dict.begin();it!=dict.end();++it)
      count++;
    cout<<count<<endl;
  }
  return 0;
}
