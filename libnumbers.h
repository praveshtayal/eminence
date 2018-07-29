#include "headers.h"

class seive {
  public:
    seive(unsigned int n);
    vector<unsigned int> primes;
  private:
  bitset<TENSIX+1> _seive;
  unsigned int size;  // This is size of seive
};
