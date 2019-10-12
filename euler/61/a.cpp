#include <bits/stdc++.h>
using namespace std;

// idea:
// generate all types of numbers
// Then, construct a 6-partite graph like so:
// for every pair of numbers of different types,
// if they (in order) form "one-side" of a cycle,
// (i.e., right two digits of first equal left two digits of second)
// put a directed edge between them.
// Then, find a cycle of length 6.

typedef long long ll;
vector<vector<int>> A (20);
map<int, set<int>> adj;
#define CONTAINS(s, x) (find((s).begin(), (s).end(), (x)) != (s).end())
int CYCLE_SIZE = 6;

int P(int k, int n)
{
    if (k == 3) return (n*(n+1))/2;  
    if (k == 4) return n*n;        
    if (k == 5) return (n*(3*n-1))/2;
    if (k == 6) return n*(2*n-1);  
    if (k == 7) return (n*(5*n-3))/2;
    if (k == 8) return n*(3*n-2);  
    cout << "BAD INPUT" << endl;
    return 0;
}

bool is_edge(int a, int b)
{
    return a % 100 == b / 100;
}

int init()
{
    for (int n = 1; n < 1000; n++) {
        for (int k = 3; k <= 8; k++) {
            int num = P(k, n);
            if (0 < num / 1000 && num / 1000 < 10) A[k].push_back(num);
        }
    }

    int cnt = 0;
    for (int i = 3; i <= 8; i++) {
        for (int j = 3; j <= 8; j++) {
            for (int a : A[i]) {
                for (int b : A[j]) {
                    if (is_edge(a, b)) {
                        cnt++;
                        adj[a].insert(b);
                    }
                }
            }
        }
    }
    cout << "graph has " << cnt << " edges." << endl;
    return 0;
}

set<int> get_types(int a)
{
    set<int> types;
    for (int i = 3; i <= 8; i++) {
        if (CONTAINS(A[i], a)) {
            types.insert(i);
        }
    }
    return types;
}

vector<int> bt(int u, vector<int> path, set<int> types)
{
    int l = path.size();
    if (l == CYCLE_SIZE) {
        // stop here
        if (is_edge(path[l-1], path[0])) {
            // we found it
            return path;
        } else {
            // we didn't find it
            return {};
        }
    }

    for (int v : adj[u]) {
        for (int t : get_types(v)) {
            if (!CONTAINS(path, v) && !CONTAINS(types, t)) {
                vector<int> _path = path;
                set<int> _types = types;
                _path.push_back(v);
                _types.insert(t);
                vector<int> res = bt(v, _path, _types);
                if (res.size() != 0) {
                    return res;
                }
            }
        }
    }
    return {};
}

int main()
{
    cout << "doing init" << endl;
    init();

    cout << "doing backtrack with level " << CYCLE_SIZE << endl;
    set<vector<int>> cycles;
    for (int i = 3; i <= 8; i++) {
        for (int u : A[i]) {
            vector<int> cycle = bt(u, {u}, get_types(u));
            if (cycle.size() != 0) { // we found it!
                sort(cycle.begin(), cycle.end());
                cycles.insert(cycle);
            }
        }
    }

    cout << "found " << cycles.size() << " cycles." << endl;

    for (vector<int> cycle : cycles) {
        cout << "cycle = ";
        for (int p : cycle) {
            cout << p << " { ";
            for (int t : get_types(p)) cout << t << " ";
            cout << "} ";
        }
        cout << endl;

        int ans= 0;
        for (int p : cycle) ans += p;
        cout << "sum = " << ans << endl;
    }
    return 0;
}
