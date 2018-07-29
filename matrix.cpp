#include "headers.h"

template<typename T>
class matrix {
  public:
    matrix(int _m, int _n, const T& value=0)
      : m(_m), n(_n)
    {
      for(int i=0; i<m; i++)
      {
        v.push_back(vector<T>(n, value));
        /*
        for(int j=0; j<n; j++)
        {
          v[i].push_back(value);
        }
        */
      }
    }

    T& operator()(int x, int y)
    {
      return v[x][y];
    }

    void print() const
    {
      for(int i=0; i<m; i++)
      {
        for(int j=0; j<n; j++)
          cout << v[i][j] << ' ';
        cout << endl;
      }
      //cout << endl;
    }

    matrix operator *(const matrix& b)
    {
      matrix c(m, b.n, 0);
      if(n!=b.m) return c;

      for(int i=0; i<m; i++)
        for(int j=0; j<b.n; j++)
          for(int k=0; k<n; k++)
            c.v[i][j] += v[i][k] * b.v[k][j];

      return c;
    }
    //matrix& power(int n);
  protected:
    vector<vector<T> > v;
    int m, n;
};

/*
  template<typename T>
matrix<T>& operator ^=(matrix<T>& a, int n)
{
  matrix<T> temp = a;
  // Why not this
  if(n==0) // Base case
  {
    // Return Identity Matrix
    a(0,0) = a(1,1) = 1;
    a(0,1) = a(1,0) = 0;
    return a;
  }
  if(n==0 || n==1) return a; // Base case
  a ^= n/2;
  a = a * a;
  if(n%2==0)
    a = a * temp;

  return a;
}
*/

template<typename T>
class squareMatrix: public matrix<T> {
  public:
  squareMatrix(int m, const T& value=0)
    : matrix<T>(m, m, value)
  {
  }
  squareMatrix(matrix<int>& m)
    : matrix<T>(m)
  {
  }
  squareMatrix operator *(const squareMatrix& b)
  {
    matrix<T>& op1 = *this;
    const matrix<T>& op2 = b;
    matrix<T> ans = op1*op2;
    return (squareMatrix)ans;
  }
  //squareMatrix(int m, const T& value=0)
  squareMatrix power(int n) const
  {
    squareMatrix ans(*this);

    if(n==0 || n==1) return ans; // Base case
    squareMatrix x = power(n/2);
    x = x * x;
    if(n%2==0)
      ans = ans * x;

    return ans;
  }
};

int main()
{
  int m=2, n=2, num;
  matrix<int> a(m,n,1);
  a(1,1)=0;
  matrix<int> b(a);
  a.print();
  cin >> num;
  for(int i=1; i<num-1; i++)
    b = b*a;
  b.print();
  cout << b(0,0) << endl;

  squareMatrix<int> s(2, 1);
  s(1,1)=0;
  squareMatrix<int> fib = s.power(num-2);
  cout << fib(0,0) << endl;
  /*
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
      cout << a(i,j) << ' ';
  cout << endl;
  squareMatrix<int> b(m,1);
  b.print();
  b.square();
  b.print();
  for(int i=0; i<m; i++)
    for(int j=0; j<m; j++)
      cout << b(i,j) << ' ';
  cout << endl;
  */
}
