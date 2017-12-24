#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

int to_digit(char c)
{
  return 'c' - '0';
}
int solve(string a)
{
  int n = a.length();
  int sum_digit[n];
  sum_digit[0] = to_digit(a[0]);
  int sum = sum_digit[0];
  for(int i=1;i<n;i++)
  {
    int num_i = to_digit(a[i]);
    sum_digit[i] = ((i+1)*num_i + 10*sum_digit[i-1]);
    res += sum_digit[i];
  }
  return res;
}
int main()
{
  string a;
  cin>>a;
  cout<<solve(a)<<endl;
  return 0;
}
