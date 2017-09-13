#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int summ(int a[],int pos)
{
  if(size==1)
      return a[size-1];
  return max(summ(a,pos),summ(a,pos+1))

}

int main()
{
  int a[5] = {};
  summ(a,0);
}
