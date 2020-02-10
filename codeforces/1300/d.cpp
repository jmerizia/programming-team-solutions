#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int N;
set<pii> S;
set<pii> Sy;

pii ad(pii a, pii b)
{
    return {a.first+b.first, a.second+b.second};
}

pii su(pii a, pii b)
{
    return {a.first-b.first, a.second-b.second};
}

void Solve()
{
    cin >> N;
    FOR(i, 0, N) {
        int x, y;
        cin >> x >> y;
        S.insert({2*x, 2*y});
        Sy.insert({2*y, 2*x});
    }
    int minx = S.begin()->first;
    int maxx = (--S.end())->first;
    int miny = Sy.begin()->first;
    int maxy = (--Sy.end())->first;
    pii c = {(minx+maxx)/2, (miny+maxy)/2};
    //cout << "c:" << c.first << ' ' << c.second << endl;
    for (pii p : S) {
        pii t = su(c, su(p, c));
        //cout << "p:" << p.first << ' ' << p.second << endl;
        //cout << "t:" << t.first << ' ' << t.second << endl;
        if (!CONTAINS(S, t)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

