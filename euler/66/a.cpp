#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> squares;

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

pair<int, int> eea(int a, int b)
{
    if (a == 0) return {0, 1};
    int c, d;
    tie(c, d) = eea(b % a, a);
    return {d - (b/a) * c, c};
}

int init()
{
    for (int i = 1; i <= 100; i++) squares.insert(i*i);
}

int main()
{
    init();
    auto pr = eea(1, -2);
    cout << pr.first << ' ' << pr.second << endl;
    return 0;
}
