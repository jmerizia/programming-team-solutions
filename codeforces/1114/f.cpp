#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
vector<int> primes;
vector<int> inv_primes;
ll prime_bits[301];

template <class T>
class SegTree {
public:
    vector<T> Tree, Lazy; T Flag; function<T(T,T,int)> Op; int Size;
    SegTree(function<T(T,T,int)> _Op, T _Flag, vector<T>& Initial_Values) {
        Op = _Op; Flag = _Flag; Size = Initial_Values.size();
        Tree.resize(Size*4, Flag); Lazy.resize(Size*4, Flag);
        for (int i = 0; i < Size; i++)
            Modify(0, 0, Size-1, i, i, Initial_Values[i]);
    }
    void Push(int node, int st, int en) {
        if (Lazy[node] == Flag) return;
        Tree[node] = Op(Tree[node], Lazy[node], en-st+1);
        if (st != en) {
            Lazy[node*2+1] = Op(Lazy[node*2+1], Lazy[node], 1);
            Lazy[node*2+2] = Op(Lazy[node*2+2], Lazy[node], 1);
        }
        Lazy[node] = Flag;
    }
    void Modify(int node, int st, int en, int left, int right, T value) {
        Push(node, st, en);
        if (st > en || en < left || right < st) return;
        if (left <= st && en <= right) {
            Lazy[node] = Op(Lazy[node], value, 1);
            Push(node, st, en);
            return;
        }
        Modify(node*2+1, st, (st+en)/2, left, right, value);
        Modify(node*2+2, (st+en)/2+1, en, left, right, value);
        Tree[node] = Op(Tree[node*2+1], Tree[node*2+2], 1);
    }
    T Query(int node, int st, int en, int left, int right) {
        Push(node, st, en);
        if (st > en || en < left || right < st) return Flag;
        if (left <= st && en <= right) return Tree[node];
        T p1 = Query(node*2+1, st, (st+en)/2, left, right);
        T p2 = Query(node*2+2, (st+en)/2+1, en, left, right);
        return Op(p1, p2, 1);
    }
};

int mult(int a, int b) { return (int64_t(a) * b) % MOD; }

int mod_pow(int a, int b, int r = 1)
{
    while (b>0) {
        if (b%2==0) {a = mult(a, a); b /= 2;}
        else {r = mult(r, a); b--; }
    }
    return r;
}

void init()
{
    // calc primes for 1..300
    // total primes: 62 => use ll bitmask w/ OR segtree
    vector<int> sieve(301, 1);
    sieve[1] = 0;
    for (int p = 2; p*p <= 300; p++) {
        if (sieve[p]) {
            for (int i = p*p; i <= 300; i += p) {
                sieve[i] = 0;
            }
        }
    }
    for (int i = 1; i <= 300; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    inv_primes.resize(primes.size());
    for (int i = 0; i < primes.size(); i++) {
        inv_primes[i] = mod_pow(primes[i], MOD-2);
    }

    for (int i = 1; i <= 300; i++) {
        ll bits = 0LL;
        for (int j = 0; j < primes.size(); j++) {
            if (i%primes[j]==0) {
                bits |= 1LL << j;
            }
        }
        prime_bits[i] = bits;
    }
}

int answer_query(SegTree<int>& treePROD, SegTree<ll>& treeOR, int l, int r, int n) {
    int product = treePROD.Query(0, 0, n-1, l, r);
    ll bits = treeOR.Query(0, 0, n-1, l, r);

    for (int i = 0; bits > 0; bits >>= 1, i++) {
        if (bits&1) {
            product = mult(product, primes[i]-1);
            product = mult(product, inv_primes[i]);
        }
    }
    return product;
}

void Solve()
{
    init();
    int n, q;
    cin >> n >> q;
    vector<int> A (n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    auto f1 = [] (int a, int b, int k) { return mult(a, mod_pow(b, k)); };
    SegTree<int> treePROD (f1, 1, A);
    // init OR tree
    vector<ll> B (n);
    for (int i = 0; i < n; i++) {
        B[i] = prime_bits[A[i]];
    }
    auto f2 = [] (ll a, ll b, int k) { return a|b; };
    SegTree<ll> treeOR (f2, 0LL, B);

    while (q--) {
        string request; cin >> request;
        int l, r; cin >> l >> r; l--; r--;
        if (request == "TOTIENT") {
            cout << answer_query(treePROD, treeOR, l, r, n) << endl;
        } else if (request == "MULTIPLY") {
            int x; cin >> x;
            treePROD.Modify(0, 0, n-1, l, r, x);
            treeOR.Modify(0, 0, n-1, l, r, prime_bits[x]);
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

// takeaways:
// for prime m, a inverse mod m is a^(m-2)
// lazy eval in seg trees require "pushing"
// or propagating a change to a node.
// Whatever is stored in Lazy, must be applied
// to that node once for each of its children.
