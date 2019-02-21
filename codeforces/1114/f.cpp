#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int MAXN = 4e5+1;
//int phi[301];
vector<pair<int, int>> prime_divisors[301];
map<int, int> bit_to_prime;
map<int, int> prime_to_bit;

template<class T>
class SEGTREE {
public:
    vector<T> t, d;
    T flag;
    int h, n;
    function<T(T, T)> op;
    SEGTREE(function<T(T, T)> _op, T _flag, vector<T>& initial_vals, int _n) {
        this->flag = _flag;  // default value (i.e. 1 if mult, 0 if add)
        this->op = _op; // pairwise operation
        this->n = _n;
        t = vector<T> (2*n);
        d = vector<T> (n, _flag);
        h = sizeof(int) * 8 - __builtin_clz(n);
        // initialize values:
        if (initial_vals.size() == _n) {
            for (int i = 0; i < n; i++) t[i+n] = initial_vals[i];
            for (int i = 0; i < n; i++) this->build(i+n);
        }
    }
    void apply(int p, T value) {
        t[p] = this->op(t[p], value);
        if (p < n /*is not leaf*/) d[p] = this->op(d[p], value);
    }
    void build(int p) { // update parents of p
        while (p > 1) {
            p >>= 1;
            t[p] = this->op(t[p<<1], t[p<<1|1]);
            t[p] = this->op(t[p], d[p]);
        }
    }
    void push(int p) {
        for (int s = h; s > 0; s--) {
            int i = p >> s;
            if (d[i] != this->flag) {
                this->apply(i<<1, d[i]);
                this->apply(i<<1|1, d[i]);
                d[i] = this->flag;
            }
        }
    }
    void modify(int l, int r, T value) {
        l += n, r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) this->apply(l++, value);
            if (r&1) this->apply(--r, value);
        }
        this->build(l0);
        this->build(r0-1);
    }
    T query(int l, int r) {
        l += n, r += n;
        this->push(l);
        this->push(r-1);
        ll res = this->flag;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = this->op(res, t[l++]);
            if (r&1) res = this->op(res, t[--r]);
        }
        return res;
    }
};

ll mult_mod(ll a, ll b, ll mod)
{
    ll res = 0;
    while (b) {
        if (b&1) res = (res + a) % mod;
        a = (a<<1)%mod;
        b >>= 1;
    }
    return res;
}

//int calc_phi(int k)
//{
//    int res = 1;
//    for (pair<int, int> pr : prime_divisors[k]) {
//        int p = pr.first, mult = pr.second;
//        int pn = 1;
//        for (int i = 0; i < mult; i++) {
//            pn = (pn * p) % MOD;
//        }
//        res = (res * (pn - pn/p)) % MOD;
//    }
//    return res;
//}


void init()
{
    set<int> primes;

    // calc divisors for 1..300
    for (int p = 1; p <= 300; p++) {
        int pp = p, ppp = p;
        for (int i = 2; i*i <= pp; i++) {
            int cnt = 0;
            while (pp%i==0) {
                pp /= i;
                cnt++;
            }
            if (cnt) {
                prime_divisors[ppp].push_back({i, cnt});
                primes.insert(i);
            }
        }
        if (pp > 1) {
            prime_divisors[ppp].push_back({pp, 1});
            primes.insert(pp);
        }
    }

    // total primes: 62 => use ll bitmask w/ OR segtree
    int cur = 0;
    for (int p : primes) {
        bit_to_prime[cur] = p;
        prime_to_bit[p] = cur;
        cur += 1;
    }

    // precompute phi for 1..300
    //for (int i = 1; i <= 300; i++) {
    //    phi[i] = calc_phi(i);
    //}
}

ll get_prime_bits(int x)
{
    ll bits = 0;
    for (pair<int, int> pr : prime_divisors[x]) {
        int p = pr.first;
        bits |= 1l << prime_to_bit[p];
    }
    return bits;
}

int answer_query(SEGTREE<ll>& treePROD, SEGTREE<ll>& treeOR, int l, int r) {
    ll product = treePROD.query(l, r);
    ll bits = treeOR.query(l, r);
    cout << product << ' ' << bitset<64>(bits) << endl;

    int bit = 0;
    while (bits != 0) {
        if (bits&1) {
            ll p = bit_to_prime[bit];
            product /= p;
            product *= p - 1;
        }
        bits >>= 1;
        bit += 1;
    }
    return product;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n, q;
    cin >> n >> q;
    vector<ll> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SEGTREE<ll> treePROD ([](ll _a, ll _b){return mult_mod(_a,_b,MOD);}, 1, a, n);
    // init OR tree
    vector<ll> init_or (n);
    for (int i = 0; i < n; i++) {
        init_or[i] = get_prime_bits(a[i]);
    }
    SEGTREE<ll> treeOR ([](ll _a, ll _b){return _a|_b;}, 0l, init_or, n);

    while (q--) {
        string query;
        cin >> query;
        if (query[0] == 'T') {
            int l, r; cin >> l >> r;
            cout << answer_query(treePROD, treeOR, l-1, r) << endl;
        } else {
            int l, r, x; cin >> l >> r >> x;
            treePROD.modify(l-1, r, x);
            ll bits = get_prime_bits(x);
            treeOR.modify(l-1, r, bits);
        }
    }

    return 0;
}
