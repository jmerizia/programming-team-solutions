#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> continued_fraction(double x, int n)
{
    // find the continued fraction of a given length
    vector<ll> cont_frac;
    ll a;
    double b;
    while (n--) {
        a = (ll) floor(x);
        b = x - a;
        cont_frac.push_back(a);
        x = 1.0 / b;
    }

    printf("cont frac: ");
    for (int k : cont_frac)
        printf("%d ",k);
    printf("\n");

    return cont_frac;
}

pll nth_convergent(vector<ll> cont_frac, int n)
{
    // calculate the reduced fraction from the continued fraction
    ll p = 1, q = 0, k;
    for (int i = n; i >= 0; i--) { // iterate backwards
        k = cont_frac[i];
        if (p > INT_MAX) {
            // this can't possibly be the answer, since q > M
            printf("overflowed\n");
            return {1e7, 1e7};
        }
        ll p_next = k * p + q;
        ll q_next = p;
        p = p_next;
        q = q_next;
    }
    //printf("%d %d\n", p, q);

    return {p, q};
}

pii bs(double x, int M)
{
    int p, q = -1, n = 1;
    int len = 40;
    vector<ll> cont_frac = continued_fraction(x, len);
    pii frac;
    for (;;) {
        frac = nth_convergent(cont_frac, n++);
        if (frac.second <= M) {
            tie(p, q) = frac;
        } else {
            break;
        }
        if (n > len) {
            break;
        }
    }
    return {p, q};
}

int main()
{
    int T, K, M;
    double x;
    cin >> T;
    while (T--) {
        cin >> K >> M >> x;
        int p, q;
        tie(p, q) = bs(x, M);
        printf("%d %d/%d\n", K, p, q);
    }
    return 0;
}
