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
    getline(cin, s);
    string m1 = "lala.";
    string m2 = "miao.";
    while (N--) {
        getline(cin, s);
        bool a = (s.size() >= m1.size()) && (s.substr(s.size()-m1.size(), m1.size()) == m1);
        bool b = (s.size() >= m2.size()) && (s.substr(0, m2.size()) == m2);
        if (a == b) {
            cout << "OMG>.< I don't know!" << endl;
        } else if (a) {
            cout << "Freda's" << endl;
        } else if (b) {
            cout << "Rainbow's" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

