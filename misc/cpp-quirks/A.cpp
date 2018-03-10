#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void foo(int n)
{
  cout << "foo: " << n << endl;
}

void bar(int n)
{
  cout << "bar: " << n << endl;
}

int main()
{

  int n = 10, count = 0;
  while (n--) ++count, foo(n), bar(n);
  cout << count << endl;

  return 0;
}
