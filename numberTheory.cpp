#include "headers.h"

int fillPrimeList(int n)
{
  /* Given an integer N, fill all the prime numbers that lies in between 2 to
   * N (both inclusive). */
  int *primeList = new int[n]; primeList[0] = 2;
  int listSize = 1;
  for(int i=2, j; i<=n; ++i)
  {
    // Check if i is prime
    for(j=0; j<listSize; ++j)
       if(i%primeList[j]==0)
         break; // not a prime no.
    if(j==listSize)
    {
      // i is prime. Add it to primeList
      primeList[listSize++] = i;
    }
  }
  return listSize;
}

bool isPrime(long n)
{
  for(long i=2; i*i<=n; i++)
    if(n%i==0) return false;
  return true;
}

long fillSeive(long n)
{
  bitset<TENTEN+1> seive;
  // seive[i] is true for all bits except 0 and 1
  seive.set(); // set all bits to true
  seive.set(0, 0); // set 0th bit to false
  seive.set(1, 0); // set 1st bit to false
  long i, count=0;
  for(i=2; i*i<=n; i++)
  {
    if(seive[i]==false) continue;
    count++;
    // All the multiples of i are not prime
    for(long j=i*i; j<=n; j+=i)
      seive[j] = false;
  }
  for(; i<=n; i++)
    if(seive[i]==true)
      count++;
  return count;
}

int gcd(int a,int b)
{
  if(a<b) return gcd(b,a);
  // Here a>b
  if(a%b==0) return b;
  return gcd(b, a%b);
}

pair<int, pair<int, int> > extendedGCD(int a,int b)
{
  pair<int, pair<int, int> > result;
  if(a<b)
  {
    result = extendedGCD(b,a);
    int temp = result.second.first;
    result.second.first = result.second.second;
    result.second.second = temp;
    return result;
  }
  // Here a>b
  if(a%b==0)
  {
    result.first = b;
    result.second.first = 0;
    result.second.second = 1;
    return result;
  }
  pair<int, pair<int, int> > smallAns = extendedGCD(b, a%b);
  result.first = smallAns.first;
  result.second.first = smallAns.second.second;
  result.second.second = smallAns.second.first - (a/b)*smallAns.second.second;
  return result;
}

int modInverse(int a, int m)
{
  pair<int, pair<int, int> > ans = extendedGCD(a, m);
  if(ans.first==1) return ans.second.first;
  return -1;
}

long modExp(long a, long b, long c)
{
  if(b==0) return 1; // Base case
  if(b%2==0)
    // b is even
    return modExp((a*a)%c, b/2, c);
  else
    // b is odd and b-1 is even
    return (modExp((a*a)%c, (b-1)/2, c) * (a%c) )%c;
}

string toBinary(long n)
{
  string ans;
  while(n)
  {
    ans = ( (n&1)?"1":"0" ) + ans;
    n >>= 1;
  }
  return ans;
}

long modExpIterative(long a, long b, long c)
{
  long ans=1, pow=a%c; // saves (a^2^i)%c for i=0 to 99
  while(b)
  {
    if(b&1) ans = (ans*pow)%c;
    b >>= 1;
    pow = (pow*pow)%c;
  }
  return ans;
}

void multiply(unsigned long a[2][2], unsigned long b[2][2], unsigned long c=0)
{
  unsigned long _a[2][2], _b[2][2];
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    {
      _a[i][j] = a[i][j] % c;
      _b[i][j] = b[i][j] % c;
      a[i][j] = 0;
    }

  // a = temp * b
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      for(int k=0; k<2; k++)
      {
        a[i][j] += (_a[i][k] * _b[k][j]) % c;
        a[i][j] %= c;
      }
}

void power(unsigned long matrix[2][2], unsigned long n, unsigned long c=0)
{
  if(n==0 || n==1) return; // Base case. But why n==0
  power(matrix, n/2, c);
  multiply(matrix,matrix, c);
  if(n%2==1)
  {
    unsigned long temp[2][2] = { {1,1}, {1,0} };
    multiply(matrix, temp, c);
  }
}

unsigned long fib(unsigned long n, unsigned long c=0)
{
  if(n<=0) return 0;
  unsigned long matrix[2][2] = { {1,1}, {1,0} };
  power(matrix,n-1, c);
  return matrix[0][0];
}

unsigned long fiboSum(unsigned long m, unsigned long n)
{
  /* Given two non-negative integers N and M (N <= M), you have to calculate
   * and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.*/
  // S(n) = fib(n+2) - 1
  // Thus, S(m)-S(n) = fib(m+2) - fib(n+1)
  unsigned long c = 1000000007;
  unsigned long fibM = fib(m+2, c);
  unsigned long fibN = fib(n+1, c);
  return (fibM - fibN + c) % c;
}

int main()
{
  /*
  pair<int, pair<int, int> > ans = extendedGCD(16, 10);
  cout << "GCD(16,10) = " << ans.first << endl;
  cout << "x = " << ans.second.first << endl;
  cout << "y = " << ans.second.second << endl;

  cout << "modInverse(5, 12) = " << modInverse(5, 12) << endl;
  cout << "modInverse(5, 17) = " << modInverse(5, 17) << endl;

  for(int i=1; i<=10; i++)
    cout << "modExp(2,i,5) where i=" << i << " is " << modExp(2,i,5) << ' ' << modExpIterative(2,i,5) << endl;

  for(int i=1; i<=10; i++)
    cout << toBinary(i) << endl;
  for(int i=1; i<=10; i++)
    cout << "modExp(2,i,5) where i=" << i << " is " << modExpIterative(2,i,5) << endl;
  for(int i=1; i<=10; i++)
    cout << fib(i) << endl;
  */

  //cout << fib(11) << endl;
  //cout << fib(21) << endl;
  cout << fiboSum(19, 10) << endl;
}
