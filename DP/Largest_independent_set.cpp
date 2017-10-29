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

typedef struct node
{
    int data;
    struct node *left, *right;
}tnode;
int liss(tnode * root)
{
  if(root==NULL)
    return 0;
  int siz_excel = liss(root->left)  + liss(root->right);
  int siz_incl = 1;
  if(root->left!=NULL)
    siz_incl += liss(root->left->left) + liss(root->left->right);
  if(root->right!=NULL)
    siz_incl += liss(root->right->left) + liss(root->right->right);
  return max(siz_incl,siz_excel);

}
int main()
{

}


// /html/body/div[1]/div[4]/div/div[1]/div[1]/div[2]/div/div[4]/ul/li[1]
