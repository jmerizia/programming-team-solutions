#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long k, x; cin >> k >> x;
        cout << 9*(k-1) + x << endl;
    }

    // 1 => 1
    // ...
    // 9 => 9
    // 10 => 1
    // 11 => 2
    // ...
    // 18 => 9
    // 19 => 10 => 1
    // 20 => 2
    // 21 => 3
    // ...
    // 28 => 10 => 1
    //
    // In general, S(x) = x % 9
    // So, given k and x, the k-th positive number t
    // for which S(t) = x is 9*(k-1) + x
    return 0;
}
