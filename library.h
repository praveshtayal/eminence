#include <iostream>

/*
template<typename T>
void swap(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}
*/

template<int N>
void get2DArray(int arr2D[][N], int row, int col)
{
  //cin >> row >> col;
  // Read the array
  for(int i=0;i<row;++i) 
    for(int j=0;j<col;++j) 
      std::cin >> arr2D[i][j];
}

template<size_t N>
void print2DArray(int arr2D[][N], int row, int col)
{
  // Print the array
  for(int i=0;i<row;++i) 
  {
    for(int j=0;j<col;++j) 
      std::cout << arr2D[i][j] << ' ';
    std::cout << std::endl;
  }
}

/*
int main()
{
  int a=5, b=10;
  std::cout << a << ' ' << b << std::endl;
  swap(a,b);
  std::cout << a << ' ' << b << std::endl;
  int arr[10][10];
  print2DArray<10> (arr, 10, 10);
}
*/
