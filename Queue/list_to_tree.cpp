#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<list>
#include<queue>

using namespace std;

typedef struct list{
  int val;
  struct list *next;
}list;

typedef struct node{
  int val;
  struct node*right;
  struct node *left;
}tree;
void push(struct ListNode** head_ref, int new_data)
{
    struct ListNode* new_node = new ListNode;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void tree_maker(tree * root,vector<int>a)
{
  int skip;
  for(int i=0;i<a.size();i++)
  {
    skip = i;
    add(i,)
  }
}
int main()
{
    struct list* head = NULL;
    push(&head, 36);
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10)
    vector<int>a;
    while(head!=NULL)
      a.push_back(head->val);
    tree *root = new(tree);
    tree_maker(root,a);
  return 0;
}
