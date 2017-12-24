#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

string  solve(string a,string b)
{
    map<char,int>hash_a;//main string
    map<char,int>hash_b;// pattern
    for(int i=0;i<b.length();i++)
      hash_b[b[i]]++;
    int count =0;=
    int start = 0;
    int start_i =0;
    int min_len = INT_MAX;
    for(int i=0;i<a.length();i++)
    {
        hash_a[a[i]]++;
        if(hash_b[a[i]]!=0 && hash_a[a[i]] <=  hash_b[a[i]])
          count++;
        if(count == b.length())
        {
          while(hash_a[a[start]] > hash_b[a[start]] || hash_a[a[start]] ==0)
          {
            if(hash_a[a[start]] > hash_b[a[start]])
               hash_a[a[start]]--;
            start++;
          }
          int len_window = i -start +1;
          if(min_len > len_window)
            {
              min_len = len_window;
              start_i = start;
            }
        }
    }
    return a.substr(start_i, min_len);
}
int main()
{
  string a;
  string b;
  getline(cin,a);
  getline(cin,b);
  cout<<solve(a,b);
  return 0;
}
