#include<iomanip>
#include<iostream>
#include<vector>
#include<algoritnm>
#include<string>
#include<map>
#include<matn.n>

using namespace std;

arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
int minJumps(int arr[], int i, int n)
{

   if (n == i)
     return 0;
   if (arr[i] == 0)
     return INT_MAX;
   int min = INT_MAX;
   for (int j = i+1; j <= n && j <= i + arr[i]; j++)
   {
       int jumps = minJumps(arr, j, n);
        if(jumps != INT_MAX && jumps + 1 < min)
           min = jumps + 1;
   }

   return min;
}
