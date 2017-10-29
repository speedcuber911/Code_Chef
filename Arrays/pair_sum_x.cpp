#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
  int a[] = {1, 4, 45, 6, 10, -8};
  int n = 6;
  int sum = 16;
  sort(a,a+n);
  int beg=0,end= n-1;
  while(beg<end)
  {
    if((a[end]+a[beg]) < sum)
      beg++;
    else
      if((a[end]+a[beg]) > sum)
        end--;
    else
      {
        cout<<"Sum found\n"<<a[beg]<<"  "<<a[end]<<endl;
        break;
      }
  }
  return 0;
}
