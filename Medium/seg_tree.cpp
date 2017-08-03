#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>

using namespace std;

struct segnode{
  int data;
  struct segnode * left;
  struct segnode * right;
};
struct segnode * parse(int level)
{
  if(level==0)
    return null;
  if(level==1)
    node->data=0;
  struct segnode * node = new(segnode);
  node->left = parse(levels-1);
  node->right = parse(levels-1);
  node->data
  return node;
}
int main()
{
int b[8] = {0,1,2,3,4,5,6,7};
vector<int>a(b,b+8);
int levels = 1 + log2(a.size());
struct segnode * root = parse(levels);
return 0;
}
