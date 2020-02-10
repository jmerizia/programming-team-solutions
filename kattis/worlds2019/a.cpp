#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int MAXN = 5e5+1;
int N, P1[MAXN], H1[MAXN], P2[MAXN], H2[MAXN];
vector<vector<int>> A1, A2;
vector<int> ans_a, ans_b;

void Solve()
{
    cin >> N;
    A1 = vector<vector<int>> (N);
    A2 = vector<vector<int>> (N);
    FOR(i, 0, N) cin >> P1[i];
    FOR(i, 0, N) cin >> H1[i];
    FOR(i, 0, N) cin >> P2[i];
    FOR(i, 0, N) cin >> H2[i];
    FOR(i, 0, N) {
        A1[i] = {P1[i], H1[i], i};
        A2[i] = {P2[i], H2[i], i};
    }
    sort(A1.begin(), A1.end());
    sort(A2.begin(), A2.end());
    set<pii> a, b;
    int p1 = A1[0][0];
    int p2 = A2[0][0];
    for (int i = 0, j = 0; i < N || j < N; ) {
        if (b.empty()) {
            while (i < N && A1[i][0] == p1) {
                b.insert({A1[i][1], A1[i][2]});
                i++;
            }
            if (i < N) p1 = A1[i][0];
        }

        if (a.empty()) {
            while (j < N && A2[j][0] == p2) {
                a.insert({A2[j][1], A2[j][2]});
                j++;
            }
            if (j < N) p2 = A2[j][0];
        }
        if (a.size() <= b.size()) {
            for (pii pr : a) {
                int h, id;
                tie(h, id) = pr;
                auto it = b.lower_bound({h+1, 0});
                if (it == b.end()) {
                    printf("impossible\n");
                    return;
                }
                ans_a.push_back(id);
                ans_b.push_back(it->second);
                b.erase(it);
            }
            a.clear(); //leave b
        } else {
            for (pii pr : b) {
                int h, id;
                tie(h, id) = pr;
                auto it = a.upper_bound({h+1, 0});
                if (it == a.begin()) {
                    printf("impossible\n");
                    return;
                }
                it--;
                ans_b.push_back(id);
                ans_a.push_back(it->second);
                a.erase(it);
            }
            b.clear(); //leave a
        }
    }
    for(int k : ans_b) cout << k+1 << ' ';
    cout << endl;
    for(int k : ans_a) cout << k+1 << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

