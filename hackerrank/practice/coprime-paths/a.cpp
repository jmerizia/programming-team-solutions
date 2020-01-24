#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

void Solve()
{
    int k = 0;
    for (int i = 0; i < 25*25*1000*1000; i++) {
        gcd(21, 34);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

