#include "headers.h"
#include "libnumbers.cpp"
#include "library.hpp"

int maximizeVolume()
{
  /* To show himself superior than Mello, Near challenged him for a task. The
   * task is:
   * There are N rectangular pillars which are 1 unit wide and have certain
   * height (say H[i] for ith pillar). Now Mello has to tell the maximum amount
   * of water (in units) that he can hold without overflowing in between these
   * pillars by arranging and joining them together.
   * Mello is not as smart as Near so he came to you for help. Can you help
   * him?
   * You cannot topple these pillars i.e. pillars should be vertical, they
   * can't be laid horizontally. Constraints are:
   * 2 <= N <= 1000 
   * 1 <= H[i] <= 10^5 */
  return 0;
}


int factorizeMin(vector<int> v)
{
  /* Fredo is assigned a task today. He is given an array A containing
   * N integers. His task is to update all elements of array to some minimum
   * value x, that is, A[i]=x ; 1≤i≤N such that product of all elements of this
   * new array is strictly greater than the product of all elements of the
   * initial array. Note that x should be as minimum as possible such that it
   * meets the given condition. Help him find the value of x.*/
  // Find out the maximum element in v
  vector<int>::iterator maxIndex = max_element(v.begin(),v.end());
  int max = *maxIndex;

  // Calculate primeNumbers till max
  seive s(max);
  // Now s.primes has list of prime nos till max
  // update count which stores prime factors of numbers in v
  int maxFactor=2, factorCount=0;
  vector<int> count(s.primes.size());
  for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
  {
    int number = *it;
    for(int i=0; number!=1 && i<s.primes.size(); i++)
      if(*it % s.primes[i] == 0)
      {
        factorCount++;
        count[i]++;
        number /= s.primes[i];
        if(s.primes[i]>maxFactor) maxFactor = s.primes[i];
      }
  }
  print(v.begin(), v.end(), " "); cout << endl;
  print(s.primes.begin(), s.primes.end(), " "); cout << endl;
  print(count.begin(), count.end(), " "); cout << endl;
  return maxFactor;
}

int main()
{
  vector<int> v;
  int size, number;
  cin >> size;
  for(int i=0; i<size; i++)
  {
    cin >> number;
    v.push_back(number);
  }
  cout << factorizeMin(v) << endl;
}
