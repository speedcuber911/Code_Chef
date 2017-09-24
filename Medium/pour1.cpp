#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
using namespace std;

int gcd(int a,int b)
{
  if(a==0)
    return b;
  else
    return gcd(b%a,a);
}
int pour(int n,int m,int d)
{
  cout<<"Running on "<<n<<","<<m<<endl;
  int n_aux = n ,m_aux=0;
  int step = 1;
  while(n_aux!=d && m_aux!=d)
  {
        cout<<"\t"<<n_aux<<"->"<<m_aux<<endl;
        int t = min(n_aux,m-m_aux);
        n_aux -=t;
        m_aux +=t;
        step++;
        if(m_aux == d || n_aux == d)
          return step;
        if(n_aux==0)
        {
          n_aux = n;
          step++;
        }
        if(m_aux == m)
        {
          m_aux = 0;
          step++;
        }
  }
  return step;
}
int minSteps(int n,int m,int d)
{
  // cout<<"entered\n";
  if(m>n)//keeping n bigger
    swap(m,n);
  if(d>n)
    return -1;
  if(d%gcd(m,n)!=0)
    {
      // cout<<"runs";
    return -1;
    }
  else
      return min(pour(n,m,d),pour(m,n,d));
}
int main()
{
  int t;
  cin>>t;
  int n,m,d;
  while(t--)
  {
    cin>>n>>m>>d;
    cout<<minSteps(m, n, d)<<endl;
  }
  return 0;
}
