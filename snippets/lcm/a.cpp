#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//snippet-begin
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int lcm(int a, int b)
{
    return ((long long) a)*((long long) b)/gcd(a, b);
}
//snippet-end

void Solve() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
