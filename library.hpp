#include <iostream>

template<typename T, int N>
void get2DArray(T arr2D[][N], int row, int col)
{
  //cin >> row >> col;
  // Read the array
  for(int i=0;i<row;++i) 
    for(int j=0;j<col;++j) 
      std::cin >> arr2D[i][j];
}

template<typename RandomAccessIterator>
void print(RandomAccessIterator start, RandomAccessIterator end,
    std::string seperator)
{
  // Print the array
  for(;start!=end;start++) 
    std::cout << *start << seperator;
}

template<typename T, size_t N>
void print2DArray(T arr2D[][N], int row, int col, std::string seperator)
{
  // Print the array
  for(int i=0;i<row;++i) 
  {
    for(int j=0;j<col;++j) 
      std::cout << arr2D[i][j] << seperator;
    std::cout << std::endl;
  }
}
