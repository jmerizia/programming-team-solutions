//time: 5:06
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int N;

void Solve()
{
    cin >> N;
    string s;
    string fil = "po";
    string jap1 = "desu";
    string jap2 = "masu";
    string kor = "mnida";
    FOR(i, 0, N) {
        cin >> s;
        if (s.substr(s.size()-fil.size(), fil.size()) == fil) {
            cout << "FILIPINO" << endl;
        } else if (s.substr(s.size()-jap1.size(), jap1.size()) == jap1 ||
                    s.substr(s.size()-jap2.size(), jap2.size()) == jap2) {
            cout << "JAPANESE" << endl;
        } else {
            cout << "KOREAN" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

