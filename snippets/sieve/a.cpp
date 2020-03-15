#include <bits/stdc++.h>
using namespace std;

//snippet-begin
bool is_prime[(int)1e6+1];
vector<int> primes;
int spf[(int)1e6+1];
int pidx[(int)1e6+1];
void run_sieve(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 1; i < n+1; i++)
        spf[i] = i;
    for (int p = 2; p*p <= n; p++)
        if (is_prime[p])
            for (int i = p*p; i <= n; i += p)
                is_prime[i] = false, spf[i]=p;
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primes.push_back(p);
    for (int i = 0; i < primes.size(); i++)
        pidx[primes[i]] = i;
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
    cout << "Indices: ";
    for (int i = 0; i < min(10, n); i++)
        cout << pidx[primes[i]] << ' ';
    cout << endl;
    cout << "SPF trick: ";
    for (int i = 2; i < min(10, n*2); i++)
        cout << spf[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
