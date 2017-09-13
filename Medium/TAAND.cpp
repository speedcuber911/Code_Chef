#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
// #include<math.h>

using namespace std;

int main()
{

  int n;
  scanf("%d",&n);
  vector<int>a(n);
  for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
  int max = -1;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i!=j)
        {
          if((a[i]&a[j])>max)
            max = a[i]&a[j];
        }
  printf("%d\n",max);
  return 0;
}
