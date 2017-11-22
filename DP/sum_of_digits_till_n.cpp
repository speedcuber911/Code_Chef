#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int sum_up(int i)
{
  return (i<10)?i:(sum_up(i%10) + sum_up(i/10));
}
int main()
{
  int n;
  cin>>n;
  int temp =0;
  for(int i=1;i<=n;i++)
      temp += sum_up(i);
  cout<<temp<<endl;
  return 0;
}
