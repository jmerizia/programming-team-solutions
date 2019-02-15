#include <bits/stdc++.h>
using namespace std;

int x, y, z, a, b, c;

bool solve()
{
    if (x > a) return false;
    a -= x;
    int gp = a+b;
    if (y > gp) return false;
    gp -= y;
    int rm = gp+c;
    if (z > rm) return false;
    return true;
}

int main()
{
    cin>>x>>y>>z>>a>>b>>c;
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
