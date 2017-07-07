#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;
void printar(vector<char>a,int n)
{
  int i=n-1;
  while(n--)
  {
    cout<<a[i];
    i--;
  }
}

int main()
{
  int t;
  vector<char> s(26);
  cin>>t;
  while(t--)
  {
    int k;
    cin>>k;
    for(int i=0;i<26;i++)
    {
        s[i]= char(i+97);
    }
    int fac=k/25;
    int temp = k%25;
    printar (s,temp+1);
    while(fac--)
      printar(s,26);
    //cout<<endl;
  }
  return 0;
}
