#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int INF = 1e8;
const int MAXN = 2e5+99;
int TC, N;
map<pii, int> MP;
string S;

void Solve()
{
    cin >> TC;
    while (TC--) {
        cin >> N >> S;
        MP.clear();
        int x = 0, y = 0;
        pii c = {x, y};
        MP[c] = 0;
        int l = 0, r = 0, ans = INF;
        FOR(i, 0, N) {
            if (S[i] == 'L') x--;
            if (S[i] == 'R') x++;
            if (S[i] == 'U') y++;
            if (S[i] == 'D') y--;
            c = {x, y};
            if (CONTAINS(MP, c)) {
                int last = MP[c];
                int nxt = i - last + 1;
                if (nxt < ans) {
                    ans = nxt;
                    l = last+1;
                    r = i+1;
                }
            }
            MP[c] = i+1;
        }
        if (ans == INF) {
            cout << "-1" << endl;
        } else {
            cout << l << ' ' << r << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

