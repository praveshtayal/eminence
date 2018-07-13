#include "headers.h"
#include <sys/time.h>

int fillPrimeList(int n);
long fillSeive(long n);

long getTimeInMicroSeconds()
{
  struct timeval time;
  gettimeofday(&time, NULL);
  return time.tv_sec * TENSIX + time.tv_usec;
}


int arr[TENSIX];

int testfunction()
{
  return 0;
}

int main()
{
  // Fill the array in decreasing order
  for(int i=0; i<TENSIX; i++)
    arr[i] = TENSIX-i;

  // time calculations
  /*
  for(int n=10; n<=TENSIX; n*=10)
  {
    cout << "Time for fillPrime is:\n";
    long startTime = getTimeInMicroSeconds();
    cout << fillPrimeList(n) << ' ';
    long endTime = getTimeInMicroSeconds();
    cout << "n=" << n << '\t' << endTime-startTime << endl;
  }
  */

  for(long n=10; n<=TENTEN; n*=10)
  {
    cout << "Time for fillSeive is:\n";
    long startTime = getTimeInMicroSeconds();
    cout << fillSeive(n) << ' ' ;
    long endTime = getTimeInMicroSeconds();
    cout << "n=" << n << '\t' << endTime-startTime << endl;
  }
}
