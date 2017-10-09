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
  vector<int>h_tree;
  int heap_size;
  int cap;
public:
  min_heap(int r)
  {
    cap = r;
    heap_size = 0;
    h_tree.resize(cap,0);
  }
  int parent(int i)
  {
    return (i-1)/2;
  }
  int left(int i)
  {
    return (2*i + 1);
  }
  int right(int i)
  {
     return (2*i + 2);
  }
  int getmin()
  {
    return h_tree[0];
  }

  void insert_key(int k)
  {
    if(heap_size == cap)
      {
        cout<<"Overflow\n";
        return;
      }
    heap_size ++;
    int pos = heap_size - 1;
    h_tree[pos] = k;
    while(pos!=0 && h_tree[parent(pos)] > h_tree[pos])
    {
      swap(h_tree[parent(pos)],h_tree[pos]);
      pos = parent(pos);
    }
  }
  void decrease_key(int i,int new_val)
  {
    cout<<"Replacing "<<h_tree[i]<<" with "<<new_val<<endl;
    int temp  = h_tree[i];
    h_tree[i] = new_val;
    if(new_val > temp)
      min_heapify(i);
    else
      while(i!= 0 && h_tree[parent(i)] > h_tree[i])
      {
        swap(h_tree[parent(i)],h_tree[i]);
        i = parent(i);
      }
  }
  void min_heapify(int i)
  {
      int l = left(i);
      int r = right(i);
      int smallest = i;
      if(l < heap_size && h_tree[l] < h_tree[i])
        smallest = l;
      if(r < heap_size && h_tree[r] < h_tree[i])
        smallest = r;
      if(smallest != i )
      {
        swap(h_tree[i], h_tree[smallest]);
        min_heapify(smallest);
      }
  }
  void disp()
  {
<<<<<<< HEAD
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l< heapsize && h_tree
=======
    for(int i=0;i<heap_size;i++)
      cout<<h_tree[i]<<" ";
>>>>>>> 0f5d8581cda01c39c15e60309b061e84a14e68da
  }
};
int main()// Some what makes sense now, lets mover over to building a heap from an array(tree) basically
{
  min_heap m = min_heap(11);
  for(int i=0;i<11;i++)
    m.insert_key(11-i);
  m.decrease_key(4,8);
  m.disp();
  return 0;
}
