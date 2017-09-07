#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
   };

   vector<string> a;
int mak(TreeNode *A,vector<char> &s)
{
  s.push_back(char(A->val));
  if(A==NULL)
    return 0;
  if(A->right==NULL && A->left==NULL)
    {
        for(int i=0;i<s.size();i++)
              cout<<s[i];
    }
    mak(A->left,s);
    mak(A->right,s);

}
int mindepth(struct TreeNode* A) {
    vector<char>s;
    mak(A,s);
    cout<<"runs";
    for(int i=0;i<a.size();i++)
      cout<<a[i];
      return 0;
}
int main()
{
  struct TreeNode *A,*B;
   A = new(TreeNode);
   B = new(TreeNode);
   A->val = 3;
   B->val = 1;
   A->right =NULL;
   A->left  = B;
   B-> right = NULL;
   B->left  = NULL;
   mindepth(A);
  return 0;
}
