#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

int maxed = 1000;
vector<vector<int> >matrix(maxed,vector<int>(maxed));
vector<int>dp(maxed,0);
vector<long long int>arr(maxed);
int finalsize;
int N;

int DFS(int V, int size){
	if(V == N || dp[V]>= size)
		return 0;
	int i;
	dp[V] = size;
	if(size > finalsize)
		finalsize = size;
	for(i = V+1; i < N; i++){
		if(matrix[V][i] == 1)
			DFS(i, size+1);
	}
	return 0;
}

int main()
{
    cin>>N;
    int i,j;
    for(i = 0; i < N; i++)
    	cin>>arr[i];
    sort(arr.begin(),arr.end());
	for(i = 0; i < N; i++){
		for(j = i+1; j < N; j++){
			if(arr[j] % arr[i] == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}
	finalsize = 1;
	for(i = 0; i < N; i++)
		DFS(i, 1);
	if(finalsize > 1)
    	printf("%d", finalsize);
	else
		printf("-1");
    return 0;
}
