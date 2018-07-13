#include "headers.h"

void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

template<int N>
void get2DArray(int arr2D[][N], int row, int col)
{
  //cin >> row >> col;
  // Read the array
  for(int i=0;i<row;++i) 
    for(int j=0;j<col;++j) 
      cin >> arr2D[i][j];
}

template<size_t N>
void print2DArray(int arr2D[][N], int row, int col)
{
  // Print the array
  for(int i=0;i<row;++i) 
  {
    for(int j=0;j<col;++j) 
      cout << arr2D[i][j] << ' ';
    cout << endl;
  }
}
