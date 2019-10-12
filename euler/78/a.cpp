#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define CONTAINS(s, x) (find((s).begin(), (s).end(), (x)) != (s).end())

const int N = 4000;
const int MOD = 100*1000;
map<int, ll> mem_p;
map<pair<int, int>, ll> mem_pk;

int hsh(int a, int b)
{
    return a * 13337 + b;
}

ll pk(int n, int k)
{
    if (n == 0 && k == 0) return 1;
    if (n <= 0 || k <= 0) return 0;
    pair<int, int> pr = {n, k};
    if (mem_pk.find({n, k}) != mem_pk.end()) return mem_pk[pr];
    ll s = (pk(n-k, k) + pk(n-1, k-1)) % MOD;
    mem_pk[pr] = s;
    return s;
}

ll p(int n)
{
    if (mem_p.find(n) != mem_p.end()) return mem_p[n];
    ll s = 0;
    for (int k = 1; k <= n; k++) {
        s = (s + pk(n, k)) % MOD;
    }
    mem_p[n] = s;
    return s;
}

//ll p(int n, int m) {
//    if (n == 0) return 1;
//    if (mem[n][m] != -1) return mem[n][m];
//    int s = 0;
//    for (int i = 1; i <= min(n, m); i++)
//        s = s + p(n-i, i);
//    mem[n][m] = s;
//    return s;
//}

int main()
{
    for (int i = 1; i < N; i++) {
        int k = p(i);
        if (k == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;

}
