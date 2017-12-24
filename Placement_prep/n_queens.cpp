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

bool _safe(vector<vector<int> >board,int row,int col)
{
    int i,j;
    int N = board.size();
    for(int i=0;i<col;i++)
      if(board[row][i])
        return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
          return false;
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if(board[i][j])
          return false;
    cout<<"Looks safe\n";
    return true;
}
void board_print(vector<vector<int> >board)
{
  int n = board.size();
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cout<<board[i][j]<<"\t";
      cout<<endl;
    }
}
bool solve(vector<vector<int> >&board,int col,int N)
{
  if (col >= N)
      return true;

  /* Consider this column and try placing
     this queen in all rows one by one */
  for (int i = 0; i < N; i++)
  {
      /* Check if queen can be placed on
        board[i][col] */
      if ( _safe(board, i, col) )
      {
          /* Place this queen in board[i][col] */
          board[i][col] = 1;

          /* recur to place rest of the queens */
          if ( solve(board, col + 1,N) )
              return true;

          /* If placing queen in board[i][col]
             doesn't lead to a solution, then
             remove queen from board[i][col] */
          board[i][col] = 0; // BACKTRACK
      }
  }

   /* If queen can not be place in any row in
      this colum col  then return false */
  return false;
  }
int main()
{
  int n;
  cin>>n;
  vector<vector<int> >board(n,vector<int>(n,0));
  solve(board,0,n);
  board_print(board);
  return 0;
}
