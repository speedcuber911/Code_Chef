#include<stdio.h>
int main()
{
 int t,k,i,j;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&k);
  if(k%25)
   for(i=97+k%25;i>=97;i--)
    printf("%c",i);
  for(j=0;j<k/25;j++)
   for(i=122;i>=97;i--)
   printf("%c",i);
  printf("\n");
 }
 return 0;
}   
