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

// class lru
// {
//     int capacity;
//     list<int>dq;
//     unordered_map<int,list<int>::iterator>dic;
//   public:
//     lru(int cap)
//     {
//       capacity = cap;
//     }
//     void add_cache(int r)
//     {
//       if(dic.find(r) = dic.end())
//       {
//         if(dq.size()==capacity)
//         {
//           dic.erase(dq.back());
//           dq.pop_back();
//         }
//       }
//       else
//         dq.erase(x);
//       dq.push_front(x);
//       dic[x] = dq.begin();
//     }
//     void display()
//     {
//       for(auto it = dq.begin();it!=dq.end();++it)
//         cout<<(*it)<<endl;
//     }
//
// };
// int main()
// {
//   int siz=4;
//   lru a(siz);
//   a.add_cache(1);
//   a.add_cache(2);
//   a.add_cache(3);
//   return 0;
// }


//
//
//
//
//
//
//
//
// int solve(vector<ListNode *>v)//  head pointers
// {
//
//   priority_queue< ListNode *,vector<ListNode *>, compare>qu;//min heap
//   for(int i=0;i<v.size();i++)
//     qu.push(v[i]);
//   ListNode * head=NULL,last;
//   while(!qu.empty())
//   {
//     ListNode * temp = qu.top();
//     qu.pop();
//     if(temp->next!=NULL)
//       qu.push(temp->next);
//     if(head == NULL)
//     {
//       head = temp;
//       last  = temp;
//     }
//     else
//     {
//       last->next = temp;
//       last = temp;
//     }
//   }
//
//
//
//
// }


void printer(vector<int>u)
{
  cout<<"This------>\t";
  for(int i=0;i<u.size();i++)
    cout<<u[i]<<" ";
  cout<<endl;
}
void genSubsets(vector<int>&A,int start,vector<int> &ans,vector<vector<int> >&res)
{
  res.push_back(ans);
  printer(ans);
  for (int i=start; i<A.size();i++)
  {
      ans.push_back(A[i]);
      genSubsets(A,i+ 1,ans,res);
      ans.pop_back();
  }
}

int main()
{
    vector<int>A(3);
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    vector<vector<int> >res;
    vector<int>ans;
    sort(A.begin(),A.end());
    genSubsets(A,0,ans,res);
    // return res;
  return 0;
}
