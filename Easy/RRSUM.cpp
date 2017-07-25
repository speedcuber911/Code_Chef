#include<stdio.h>
int  main()
{
    long long int n,m,q,z;
    scanf("%lld %lld",&n,&m);
    z=(2*n)+1;
    while(m--)
    {
        scanf("%lld",&q);
        if(q<(n+2))
            printf("0\n");
        else
          if(q == z)
            printf("%lld\n",n);
        else
          if(q<z)
            printf("%lld\n",q-n-1);
        else
          if(q>z)
            printf("%lld\n",(3*n)-q+1);
    }
    return 0;
}
