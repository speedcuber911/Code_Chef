#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

int main()
{
  int t; cin>>t;
  while(t--) 
  { long long int i,j,n=0; cin>>i>>j;

    while(i!=j)
    {
        if(i>j)
        {
            i=i/2;
            n++;

        }
        if(j>i)
        {
            j=j/2;
            n++;
        }
    }
    cout<<n<<endl;
}
return 0;
}
