#include "libnumbers.h"

/*
class seive {
  public:
    seive(unsigned int n);
    vector<unsigned int> primes;
  private:
  bitset<TENTEN+1> _seive;
  unsigned int size;  // This is size of seive
};
*/
seive::seive(unsigned int n)
{
  // _seive[i] is true for all bits except 0 and 1
  _seive.set(); // set all bits to true
  _seive.set(0, 0); // set 0th bit to false
  _seive.set(1, 0); // set 1st bit to false
  unsigned int i;
  for(i=2; i*i<=n; i++)
  {
    if(_seive[i]==false) continue;
    primes.push_back(i);
    // All the multiples of i are not prime
    for(int j=i*i; j<=n; j+=i)
      _seive[j] = false;
  }
  for(; i<=n; i++)
    if(_seive[i]==true)
      primes.push_back(i);
}
