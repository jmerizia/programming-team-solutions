// dep:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define c2(x, y, a) x(y(a))
#define c3(x, y, z, a) x(y(z(a)))
#define all(v) v.begin(), v.end()
#define DO(i, a, b) for (int i = (a); i < (b); ++i)
#define DOd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define Edges(int) set<pair<int, int>>
#define CONTAINS(C, x) (C.find(x) != C.end())
#define range(v, a, b) vector<int> v((b)-(a)+1); iota(v.begin(),v.end(),a)
#define between(c, a, b) ((a) <= (c) && (c) <= (b))
// dep:
string format(string s, vector<string> v);
template <class T> string to_string(pair<T, T> p);
template <class T> string to_string(set<T> m);

/*
 * Takes a string and a vector of strings,
 * replacing each instance of {} with the
 * corresponding vector element.
 */
string format(string s, vector<string> v) {
    string o;
    if (s.size() == 0) return o;
    int c = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i < (int)s.size() - 1 && s[i] == '{' && s[i+1] == '}') {
            assert((int)v.size() != c);
            o += v[c++], i++;
        } else {
            o += s[i];
        }
    }
    return o;
}

/*
 * Returns a string representation of a generic pair<T, T>.
 */
template <class T>
string to_string(pair<T, T> p) {
    return format("({}, {})", {to_string(p.first), to_string(p.second)});
}

/*
 * Returns a string for a generic set<T>.
 */
template <class T>
string to_string(set<T> m) {
    string s = "{";
    int idx = 0, sz = m.size();
    for (T elem : m) {
        s += to_string(elem);
        if (++idx < sz) s += ", ";
    }
    s += "}";
    return s;
}

/*
 * Returns a string for a generic vector<T>.
 */
template <class T>
string to_string(vector<T> m) {
    string s = "{";
    int idx = 0, sz = m.size();
    for (T elem : m) {
        s += to_string(elem);
        if (++idx < sz) s += ", ";
    }
    s += "}";
    return s;
}

/*
 * Returns a string for a generic map<T, T>.
 */
template <class T>
string to_string(map<T, T> m) {
    string s = "{";
    int idx = 0, sz = m.size();
    for (pair<T, T> elem : m) {
        s += to_string(elem);
        if (++idx < sz) s += ", ";
    }
    s += "}";
    return s;
}

// dep:string
template <class T>
struct Set {
    // A general set data structure that depends only on STL
    set<T> s;
    Set(set<T> _s) {
        this->s = _s;
    }
    Set() {}
    void insert(T e) { this->s.insert(e); }
    void clear() { this->s.clear(); }
    int size() const { return this->s.size(); }
    bool empty() const { return this->s.empty(); }
    void remove(T e) { this->s.erase(this->s.find(e)); }
    typename set<T>::iterator begin() const { return this->s.begin(); }
    typename set<T>::iterator end() const { return this->s.end(); }
    Set<T> operator+(const Set<T>& other) {
        Set nw = this->s;
        for (T e : other.s) nw.insert(e);
        return nw;
    }
    bool contains (T e) const {
        return (s.find(e) != s.end());
    }
    Set<T>& operator+=(const Set<T>& other) {
        for (T e : other.s) this->s.insert(e);
        return *this;
    }
    bool operator<(const Set<T>& other) const {
        return this->s < other.s;
    }
    Set<T> operator&(const Set<T>& other) const {
        Set<T> nw;
        for (T e : other) if (this->contains(e)) nw.insert(e);
        return nw;
    }
};

/*
 * Returns a string for a generic Set<T>.
 */
template <class T>
string to_string(Set<T> m) {
    return to_string(m.s);
}

Set<int> rng(int a, int b) {
    Set<int> k;
    for (int i = a; i < b; i++) k.insert(i);
    return k;
}
Set<int> rng(int a, int b, int c) {
    Set<int> k;
    for (int i = a; i < b; i+=c) k.insert(i);
    return k;
}
// dep:
template <class T>
struct ImplicitEdgeGraph {
    // A general implicit graph class.
    function<bool(T, T)> has_edge;
    ImplicitEdgeGraph(function<bool(T, T)> _has_edge) {
        has_edge = _has_edge;
    }
    Set<Set<T>> disjoint_components(Set<T> nodes) { // O(V)
        Set<T> not_vis = nodes;
        Set<Set<T>> disjoint_sets;
        while (!not_vis.empty()) {
            queue<T> Q;
            T root = *not_vis.begin();
            Set<T> connected_set ({root});
            not_vis.remove(root);
            Q.push(root);
            while (!Q.empty()) {
                T u = Q.front();
                Q.pop();
                for (T v : not_vis) {
                    if (this->has_edge(u, v)) {
                        connected_set.insert(v);
                        not_vis.remove(v);
                        Q.push(v);
                    }
                }
            }
            disjoint_sets.insert(connected_set);
        }
        return disjoint_sets;
    }
};
// https://codeforces.com/contest/653/problem/E

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Set<pii> edges;
    DO (i, 0, n) {
        int u, v;
        cin >> u >> v;
        edges.insert({u, v});
    }
    auto f = [edges](int a, int b) {
        return !(edges.contains({a, b}) || edges.contains({b, a}));
    };
    ImplicitEdgeGraph<int> IG (f);
    auto C1 = IG.disjoint_components(rng(1, n+1));
    if (C1.size() > 1)
        cout << "impossible", exit(0);
    auto C2 = IG.disjoint_components(rng(2, n+1)); // connected by 1
    int d = 0;
    for (int node : rng(2, n+1)) if (f(1, node)) d++;
    if (between(k, C2.size(), d))
        cout << "possible";
    else
        cout << "impossible";
}
