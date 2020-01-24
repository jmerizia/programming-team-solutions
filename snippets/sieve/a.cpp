#include <bits/stdc++.h>
using namespace std;

//snippet-begin
vector<bool> is_prime ((int)1e6);
vector<int> primes;
void run_sieve(int n)
{
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < n; i++)
        is_prime[i] = true;
    for (int i = 2; i < n; i++)
        if (is_prime[i])
            for (int j = i*i; j < n; j += i)
                is_prime[j] = false;
    for (int i = 1; i < n; i++)
        if (is_prime[i])
            primes.push_back(i);
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
