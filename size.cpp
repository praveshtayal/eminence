#include "headers.h"
#include <sys/resource.h>

class BigObject
{
  public:
  int arr[TENSIX];
};

int arr[TENNINE];
//int arr2[TENTEN]; Gives Linking Error
int main()
{
  cout << "Integer " << sizeof(int) << ' ' << INT_MIN << ' ' << INT_MAX << endl;
  cout << "Long " << sizeof(long) << ' ' << LONG_MIN << ' ' << LONG_MAX << endl;

  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  const rlim_t mb = 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  cout << "result for stack sizes in MB are " << result << endl;
  cout << "rlim_cur = " << rl.rlim_cur/mb << endl;
  cout << "rlim_max = " << rl.rlim_max/mb << endl;

  result = getrlimit(RLIMIT_AS, &rl);
  cout << "result for address sizes in MB are " << result << endl;
  cout << "rlim_cur = " << rl.rlim_cur/mb << endl;
  cout << "rlim_max = " << rl.rlim_max/mb << endl;

  result = getrlimit(RLIMIT_DATA, &rl);
  cout << "result for data sizes in MB are " << result << endl;
  cout << "rlim_cur = " << rl.rlim_cur/mb << endl;
  cout << "rlim_max = " << rl.rlim_max/mb << endl;

  result = getrlimit(RLIMIT_FSIZE, &rl);
  cout << "result for file sizes in MB are " << result << endl;
  cout << "rlim_cur = " << rl.rlim_cur/mb << endl;
  cout << "rlim_max = " << rl.rlim_max/mb << endl;

  /* Change stack Size
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
  */
  /* Cant create array of bigObjects
  int localArr[TENSIX];

  localArr[TENSIX-1] = 500;
  cout << localArr[TENSIX-1] << endl;

  arr[TENNINE-1] = 501;
  cout << arr[TENNINE-1] << endl;

     BigObject bo[10];
     bo[10-1].arr[TENSIX-1] = 10;
     cout << bo[10-1].arr[TENSIX-1] << endl;
   ************************************/
}
