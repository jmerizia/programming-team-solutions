#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define CONTAINS(set, x) (set.find(x) != set.end())

set<vi> vset, hset;

bool check_intersection(vi ve, vi ho) {
    return ve[1] < ho[0] && ve[0] < ve[2] && ho[1] < ve[0] && ve[0] < ho[2];
}

bool Query(set<vi>& st, vi query) {
    auto left = st.lower_bound({query[1], 0, 0});
    auto right = st.upper_bound({query[2], 0, 0});
    for (; left != right; left++) {
        if (check_intersection(*left, query)) {
            return 1;
        }
    }
    return 0;
} 

void Solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        vi v1 = {x1, y1, y2};
        vi v2 = {x2, y1, y2};
        vi h1 = {y1, x1, x2};
        vi h2 = {y2, x1, x2};
        //check intersections
        if (Query(vset, h1) || Query(vset, h2) ||
            Query(hset, v1) || Query(hset, v2)) {
            cout << "1";
            return;
        }

        // no intersections
        vset.insert(v1);
        vset.insert(v2);
        hset.insert(h1);
        hset.insert(h2);
    }
    cout << "0";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}


// shift tilde
