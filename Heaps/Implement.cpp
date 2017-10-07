#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stack>
#include<list>

using namespace std;

class min_heap{
  int cap;
  vector<int>h_tree;
  int heapsize;
public:
  min_heap(int sizer)
  {
    heapsize=0;
    cap = sizer;
    h_tree.resize(sizer,0);
  }
  int left(int i){return 2*i+1);}
  int right(int i){return 2*(i+1);}
  int parent(int i){return (i-1)/2;}

  void insert_key(int k)
  {
    if(heapsize==cap)
      {
        cout<<"Overflow\n";
        return ;
      }
    heapsize++;
    h_tree[heapsize-1] = k;
    int i = heapsize heapsize-1;
    while(i!=0 && h_tree[parent(i)] > h_tree[i])
      {
        swap(h_tree[parent(i),h_tree[i]);
        i = parent(i);
      }
  }
  void decrease_key(int i,int val)
  {
    h_tree[i] = val;
    while(i!=0 && h_tree[parent(i)] > h_tree[i])
      i = parent(i);
  }
  int extract_min()
  {
    if(heapsize<=0)
      return INT_MAX;
    if(heapsize==1)
        return h_tree[--heapsize];
    int root = h_tree[0];
    h_tree = h_tree[heapsize-1];
    heapsize--;
    heapify(0);
    return root;
  }
  void delete(int i)
  {
      decrease_key(i,INT_MIN);
      extract_min();
  }
  void heapify(int i)
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    

  }
};
int main()
{

  return 0;
}
