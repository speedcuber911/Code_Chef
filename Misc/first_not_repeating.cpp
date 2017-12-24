#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<map>

using namespace std;

typedef struct dlnode{
  struct dlnode * prev;
  struct dlnode * next;
  char a;
}dlnode;

void first_not_repeating()
{
  vector<dlnode*> indl(256,NULL);
  vector<bool>repeat(256,0);
  string rep;
  geline(cin,rep);
  for(int i=0;i<rep.length();i++)
  {
        char c = rep[i];
        cout<<"Processing "<<c<<endl;
        if(repeated[c]==false)
        {
          if(indl[c]==NULL)
          {
            append(&head,&tail,c);
            indl[c] = tail;
          }
          else
          {
            remove(&head,&tail,indl[c]);
            indl[c] = NULL;
            repeat[c] = true;
          }
        }
        if(head!=NULL)
          cout<<"First char repeated so far "<<head->a;
  }
}
int main()
{
  first_not_repeating();
  return 0;
}
