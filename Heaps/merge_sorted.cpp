#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

void min_heapify(pair<int,int> * arr,int n,int i)
{
  int l = 2*i+1;
  int r = 2*(i+1);
  int smallest = i;
  if(arr[smallest].first > arr[l].first && l < n)
    smallest = l;
  if(arr[smallest].first > arr[r].first && r < n)
    smallest = r;
  if(smallest!=i)
    {
      swap(arr[smallest],arr[i]);
      min_heapify(arr,n,smallest);
    }
}

pair<int,int> extract_min(pair<int,int> heap[],int n,int new_val)
{
    pair<int,int>temp = heap[0];
    return temp;
}
int merge_k(int arr[][4],int k)
{
    int t_arr[4*k];
    pair<int,int> * heap;
    heap = new pair<int,int>[4];
    vector<int>pos_param(4,0);
    for(int i=0;i<k;i++)
        {
          heap[i].first  = arr[i][0];
          heap[i].second = i;
        }
    for(int i= (n/2-1);i>=0;i--)
      heapify(heap,4,i);
    for(int i=0;i<4*k;i++)
      {
        t_arr[i] = extract_min(heap,4);
      }
}

int main()// The only problem is, I cant work my way around the fact, why is (n/2-1), the first non leaf adress.
{
  int arr[][n] =  {{2, 6, 12, 34},
                       {1, 9, 20, 1000},
                       {23, 34, 90, 2000}};
  int k  = 3;
  merge_k(arr,k);
  return 0;
}
