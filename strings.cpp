#include "headers.h"

int main()
{
  string s1 = "abc";
  string s2("def");
  string s3;
  // cin >> s3;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;

  string a("Coding Ninjas");
  cout << a<< endl;
  cout << a.length() << endl;
  cout << a.capacity() << endl;
  cout << a.find("in") << endl;
  cout << a[13] << endl;
  cout << a[14] << endl;
  a.resize(50,'a');
  a.shrink_to_fit();
  cout << a<< endl;
  cout << a.size() << endl;
  cout << a.capacity() << endl;
}
