#include<iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int sum=0;
  int i=1;
  bool found=0;
  while(n--)//The no. of times the outer loop runs
  {
    while(!found)//A counter to look for nos. divisible by 5 or 13
      {
        i++;
        if(i%5==0 || i%13==0)//If i divisible by 5 or 13 then break the loop and look for next
          {
            found=1;
            sum+=i;
          }
      }
      found=0;
  }
  cout<<sum<<endl;
  return 0;
}
