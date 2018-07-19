#include "headers.h"
#include "library.hpp"

bool checkBoard(const vector< vector<int> >& board, int n)
{
  int i, j, d, count;
  // Each Row should have at max one queen
  for(i=0; i<n; i++)
  {
    count = 0;
    for(j=0; j<n; j++)
      count += board[i][j];
    if(count>1) return false;
  }

  // Each Col should have at max one queen
  for(j=0; j<n; j++)
  {
    count = 0;
    for(i=0; i<n; i++)
      count += board[i][j];
    if(count>1) return false;
  }

  // Each Diagnol should have at max one queen
  for(d=0; d<n; d++)
  {
    count = 0;
    for(i=d, j=0; i<n && j<n; i++, j++)
      count += board[i][j];
    if(count>1) return false;

    count = 0;
    for(i=d, j=0; i>=0 && j<n; i--, j++)
      count += board[i][j];
    if(count>1) return false;
  }

  for(d=1; d<n; d++)
  {
    count = 0;
    for(i=0, j=d; i<n && j<n; i++, j++)
      count += board[i][j];
    if(count>1) return false;

    count = 0;
    for(i=n-1, j=d; i>=0 && j<n; i--, j++)
      count += board[i][j];
    if(count>1) return false;
  }

  return true;
}

void placeNQueens(int n, int row, vector< vector<int> >& board){
  if(row==n)
  {
    // Print the board in one line
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cout << board[i][j] << ' ';
    cout << endl;
    return;
  }

  for(int j=0; j<n; j++)
  {
    board[row][j] = 1;
    if(checkBoard(board, n) == true)
      placeNQueens(n, row+1, board);
    board[row][j] = 0;
  }
}

void placeNQueens(int n){
  /* You are given N, and for a given N x N chessboard, find a way to place
   * N queens such that no queen can attack any other queen on the chess board.
   * A queen can be killed when it lies in the same row, or same column, or the
   * same diagonal of any of the other queens. You have to print all such
   * configurations.*/
  vector< vector<int> > board(n);
  
  // Initialize the board to 0
  for(int i=0; i<n; i++)
  {
    board[i] = vector<int>(n);
    for(int j=0; j<n; j++)
      board[i][j] = 0;
  }

  placeNQueens(n, 0, board);
}

void placeNQueens2(int n){
  /* You are given N, and for a given N x N chessboard, find a way to place
   * N queens such that no queen can attack any other queen on the chess board.
   * A queen can be killed when it lies in the same row, or same column, or the
   * same diagonal of any of the other queens. You have to print all such
   * configurations.*/
  bitset<100> board;  // bitset is initialized by default to 0
  
  // Initialize the board to 0
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
    }
  }

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {
    }
}

void ratInAMaze(int maze[][20], int path[][20], int x, int y, int n){
  if(x==n-1 && y==n-1)
  {
    path[x][y] = 1;
    // print the path
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cout << path[i][j] << ' ';
    cout << endl;
    path[x][y] = 0;
    return;
  }

  if(x<0 || x>n-1 || y<0 || y>n-1 || maze[x][y] == 0 || path[x][y] == 1)
    return;
  path[x][y] = 1;
  ratInAMaze(maze, path, x-1, y, n);
  ratInAMaze(maze, path, x+1, y, n);
  ratInAMaze(maze, path, x, y-1, n);
  ratInAMaze(maze, path, x, y+1, n);
  path[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n){
  /* You are given a N*N maze with a rat placed at maze[0][0]. Find and print
   * all paths that rat can follow to reach its destination i.e.
   * maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and
   * down).
   * Value of every cell in the maze can either be 0 or 1. Cells with value
   * 0 are blocked means rat can­not enter into those cells and those with
   * value 1 are open.
   * You need to explore path in following order - Up , Down,Left,Right */
  int path[20][20] = { {0} };
  ratInAMaze(maze, path, 0, 0, n);
}

bool isFeasible(vector<int>& stalls, int cows, int distance)
{
  // 1st cow is placed at index prev
  int prev=0, next, size=stalls.size();
  while(--cows) {
    // Try to place next cow at index next
    for(next=prev+1; next<size && stalls[next]-stalls[prev]<distance; next++);
    if(next==size) return false;
    prev = next;
  }
  return true;
}

int aggressiveCows(vector<int>& stalls, int cows)
{
  if(cows>stalls.size() || cows<0) return 0;

  sort(stalls.begin(), stalls.end());
  int ans=1, min = ans, max = (stalls[stalls.size()-1] - stalls[0]) / (cows-1);
  while(max>=min)
  {
    int mid = (min+max+1)/2;
    if(isFeasible(stalls, cows, mid)) {
      ans = mid;
      min = mid+1;
    } else
      max = mid-1;
  }
  return ans;
}

long power(int x, int n)
{
  // Write a program to find x to the power n (i.e. x^n) 
  if(n<=0) return 1;
  if(n==1) return x;

  long ans = power(x,n/2);
  ans *= ans;
  if(n%2) ans *= x;
  return ans;
}

int murder()
{
  /* Once detective Saikat was solving a murder case. While going to the crime
   * scene he took the stairs and saw that a number is written on every stair.
   * He found it suspicious and decides to remember all the numbers that he has
   * seen till now. While remembering the numbers he found that he can find
   * some pattern in those numbers. So he decides that for each number on the
   * stairs he will note down the sum of all the numbers previously seen on the
   * stairs which are smaller than the present number. Calculate the sum of all
   * the numbers written on his notes diary.*/
  return 0;
}

#define NINE 9
bool sudokuSolver(int board[][9]){
  /* Given a 9*9 sudoku board, in which some entries are filled and others are
   * 0 (0 indicates that the cell is empty), you need to find out whether the
   * Sudoku puzzle can be solved or not i.e. return true or false.*/
  int row[9]={0}, col[9]={0}, box[3][3]={0};
  for(int i=0; i<NINE; i++)
  {
    for(int j=0; j<NINE; j++)
      cout << board[i][j] ;
    cout << endl;
  }
  for(int i=0; i<NINE; i++)
    for(int j=0; j<NINE; j++)
      if(board[i][j]==0)
      {
        (row[i])++;
        (col[j])++;
        //cout << i << ' ' << j << endl;
        (box[i/3][j/3])++;
      }
  for(int i=0; i<NINE; i++) cout << row[i]; cout << endl;
  for(int i=0; i<NINE; i++) cout << col[i]; cout << endl;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      cout << box[i][j];
  cout << endl;
  return true;
}

int main()
{
  //placeNQueens(5);

  //int maze[20][20] = { {1,0,1}, {1,1,1}, {1,1,1} };
  /*
  int maze[20][20];
  int mazeSize; cin >> mazeSize; get2DArray<int, 20>(maze, mazeSize, mazeSize); 
  ratInAMaze(maze, mazeSize);
  */

  /* Aggressive Cows
  int testCases; cin >> testCases;
  while(testCases--)
  {
    int stall, stallSize, cows; cin >> stallSize >> cows;
    vector<int> stalls;
    for(int i=0; i<stallSize; i++)
    {
      cin >> stall;
      stalls.push_back(stall);
    }
    cout << aggressiveCows(stalls, cows) << endl;
  }
  */
  //int x, n; cin>>x>>n; cout << power(x,n) << endl;

  int sudoku[NINE][NINE];
  get2DArray<int, NINE>(sudoku, NINE, NINE);
  cout << (sudokuSolver(sudoku)? "true":"false") << endl;
}
