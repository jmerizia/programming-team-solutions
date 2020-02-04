#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define all(a) (a).begin(), (a).end()

bool is_prime[(int)1e6+1];
vector<int> primes;
void run_sieve(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    for (int p = 2; p*p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p*p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

template <class T>
T gcd(T a, T b)
{
    if (a == 0) {
        return b;
    } else {
        return gcd(b%a, a);
    }
}

ll totient(ll n)
{
    unordered_map<ll, int> pf;
    while (n > 1) {
        bool changed = false;
        for (int p : primes) {
            if (n%p == 0) {
                if (CONTAINS(pf, p)) {
                    pf[p]++;
                } else {
                    pf[p] = 1;
                }
                changed = true;
                n /= p;
            }
        }
        if (!changed) break;
    }
    if (n > 1) {
        pf[n] = 1;
    }
    ll tot = 1;
    for (pair<ll, int> pr : pf) {
        ll p, m;
        tie(p, m) = pr;
        ll d = (ll)pow(p, m);
        ll e = (ll)pow(p, m-1);
        tot *= (d-e);
    }
    return tot;
}

int TC;
ll A, M;

void Solve()
{
    run_sieve(1e5);
    cin >> TC;
    while (TC--) {
        cin >> A >> M;
        ll ans = totient(M/gcd<ll>(A, M));
        printf("%lld\n", ans);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

