#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n>>m>>k;
    vector<pair<int, int>> a(n);
    vector<int> b(n), p(k-1), marked(m*k);
    for (int i = 0; i < n; i++) {
        int aa; cin >> aa;
        a[i] = {aa, i};
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    ll ans = 0;
    for (int i = 0; i < m*k; i++) {
        marked[i] = a[i].second;
        ans += a[i].first;
    }
    sort(marked.begin(), marked.end());
    for (int i = 0; i < k-1; i++) {
        p[i] = marked[(i+1)*m-1]+1;
    }

    cout << ans << endl;
    for (int pp : p) cout << pp << ' ';
    cout << endl;

    return 0;
}
