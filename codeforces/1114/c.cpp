#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> prime_fac(ll b)
{
    vector<pair<ll, ll>> fa;
    for (ll i = 2; i*i <= b; i++) {
        ll tot = 0;
        while (b % i == 0) {
            tot++;
            b /= i;
        }
        if (tot) {
            fa.push_back({i, tot});
        }
    }
    if (b > 1) fa.push_back({b, 1});
    return fa;
}

ll calc(ll n, ll p)
{
    // largest power of p that divides n!
    ll tot = 0;
    while (n > 0) {
        tot += n / p;
        n /= p;
    }
    return tot;
}

int main()
{
    ll n, b;
    cin>>n>>b;
    vector<pair<ll, ll>> fa = prime_fac(b);
    ll ans = LLONG_MAX;
    for (pair<ll, ll> pr : fa) {
        ll p = pr.first, y = pr.second;
        ll x = calc(n, p);
        ans = min(ans, x/y);
    }
    cout << ans << endl;

    return 0;
}

// Since n is very big, no chance to compute n!
//
// So to figure out how many times b divides n!,
// for each prime factor (and power) of b, O(logb) ~=40
// test the number of times it divides n!,
// and report the overall min.
// To figure out how many times a number p divides n!,
// determine the number of numbers n..1 that are divisible at
// least once by p O(1), then by at least p^2, and so on.
// However, this approach leads to overflow, since p can be
// as large as b, so b^i can be larger than LLONG_MAX for
// some i.
// So instead, instead of computing...
// n/(p^1) + n/(p^2) + ... + n/(p^i) (until p^i > n)
// ...compute the following equivalent:
// n/p + (n/p^1)/p + (n/p^2)/p + ... (n/p^i)/p (while n/p^i > 0)
//
// Takeaways:
// - It's good to think on paper first
// - Understand the combinatorics equations very well before implement
// - ll vs int (10^19 and 10^9)
// - don't screw up easy things like well known prime factorization alg
