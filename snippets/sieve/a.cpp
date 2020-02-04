#include <bits/stdc++.h>
using namespace std;

//snippet-begin
bool is_prime[(int)1e6+1];
vector<int> primes;
void run_sieve(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    for (int p = 2; p*p <= n; p++)
        if (is_prime[p])
            for (int i = p*p; i <= n; i += p)
                is_prime[i] = false;
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primes.push_back(p);
}
//snippet-end

void Solve() {
    int n;
    cin >> n;
    run_sieve(n);
    cout << "Primes: ";
    for (int i = 0; i < min(10, n); i++)
        cout << primes[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
