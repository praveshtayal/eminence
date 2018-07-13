#include "headers.h"

static int primeList[TENSIX] = {2,3,5,7,11,13,17,19,23,29,31,37};
static int listSize = 12;

int fillPrimeList(int n)
{
  /* Given an integer N, fill all the prime numbers that lies in between 2 to
   * N (both inclusive). */
  for(int i=primeList[listSize-1], j; i<=n; ++i)
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

bitset<TENTEN+1> seive;
long fillSeive(long n)
{
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
  if(a<b) {
    int temp = a; a=b; b=temp;
  }
  // Here a>b
  if(a%b==0) return b;
  return gcd(b, a%b);
}

pair<int, pair<int, int> > extendedGCD(int a,int b)
{
  if(a<b) {
    int temp = a; a=b; b=temp;
  }
  // Here a>b
  pair<int, pair<int, int> > result;
  if(a%b==0)
  {
    result.first = b;
    result.second.first = 0;
    result.second.second = 1;
    //result.second.first = 1;
    //result.second.second = (-1)*a/b;
    return result;
  }
  pair<int, pair<int, int> > smallAns = extendedGCD(b, a%b);
  result.first = smallAns.first;
  result.second.first = smallAns.second.second;
  //result.second.second = smallAns.second.first - floor(a/b)*smallAns.second.second;
  result.second.second = smallAns.second.first - (a/b)*smallAns.second.second;
  return result;
}

int modInverse(int a, int m)
{
  pair<int, pair<int, int> > ans = extendedGCD(a, m);
  if(ans.first==1) return ans.second.first;
  return -1;
}


int main()
{
  pair<int, pair<int, int> > ans = extendedGCD(5, 12);
  cout << "GCD(16,10) = " << ans.first << endl;
  cout << "x = " << ans.second.first << endl;
  cout << "y = " << ans.second.second << endl;

  cout << "modInverse(5, 12) = " << modInverse(5, 12) << endl;
  cout << "modInverse(5, 17) = " << modInverse(5, 17) << endl;
}
