#include <bits/stdc++.h>
using namespace std;

//snippet-begin
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
//snippet-end

void Solve() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
