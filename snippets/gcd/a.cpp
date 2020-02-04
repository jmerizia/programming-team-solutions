#include <bits/stdc++.h>
using namespace std;

//snippet-begin
template <class T>
T gcd(T a, T b)
{
    if (a == 0) {
        return b;
    } else {
        return gcd(b%a, a);
    }
}
//snippet-end

void Solve() {
    int a, b;
    cin >> a >> b;
    cout << gcd<int>(a, b) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
