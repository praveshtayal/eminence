#include "headers.h"

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

int minDistance(vector<int>& solution, vector<int>& stalls, int cows)
{
  int distance = abs(stalls[solution[0]] - stalls[solution[1]]);
  for(int i=0; i<solution.size(); i++)
    for(int j=0; j<solution.size(); j++)
      if( i!=j && abs(stalls[solution[i]] - stalls[solution[j]]) < distance)
        distance = abs(stalls[solution[i]] - stalls[solution[j]]);
  return distance;
}

int aggressiveCows(vector<int>& stalls, int cows)
{
  if(cows>stalls.size() || cows<0) return 0;
  if(cows<2)
  {
    return INT_MAX;
  }

  vector<int> candidate, solution;
  for(int i=0; i<cows; i++)
  {
    candidate.push_back(i);
    solution.push_back(i);
  }
  int solutionDistance = minDistance(solution, stalls, cows);
  return solutionDistance;
}

void get2DArray(int arr2D[][20], int row, int col)
{
  //cin >> row >> col;
  // Read the array
  for(int i=0;i<row;++i) 
    for(int j=0;j<col;++j) 
      cin >> arr2D[i][j];
}

int main()
{
  placeNQueens(8);

  //int maze[20][20] = { {1,0,1}, {1,1,1}, {1,1,1} };
  /*
  int maze[20][20];
  int mazeSize; cin >> mazeSize; get2DArray(maze, mazeSize, mazeSize); 
  ratInAMaze(maze, mazeSize);
  */

  // Aggressive Cows
  /*
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
}
