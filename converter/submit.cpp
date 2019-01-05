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

template <class T>
string to_string(list<T> m) {
  string s = "{";
  int idx = 0, sz = m.size();
  for (T e : m) {
    s += to_string(e);
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
// dep:Set
template <class T>
struct UnionFind {
    // A general UnionFind Data Structure
    map<T, T> parent;
    UnionFind(vector<T> items) {
        for (T item : items) parent[item] = item;
    }
    UnionFind(set<T> items) {
        for (T item : items) parent[item] = item;
    }
    UnionFind(Set<T> items) {
        for (T item : items) parent[item] = item;
    }
    T leader(T a) {
        T cur = a;
        while (cur != parent[cur]) cur = parent[cur];
        return cur;
    }
    void compress(T a) {
        T lead = this->leader(a);
        T cur = this->parent[a];
        while (cur != parent[cur]) {
            parent[cur] = lead;
            cur = parent[cur];
        }
    }
    void UNION(T a, T b) {
        T leader_a = leader(a);
        T leader_b = leader(b);
        if (leader_a != leader_b) parent[leader_b] = leader_a;
    }
    bool FIND(T a, T b) {
        compress(a);
        compress(b);
        return leader(a) == leader(b);
    }
};
// dep:string,Set,UnionFind
template <class T>
struct Graph {
    // A general directed graph data structure
    map<T, Set<T>> adj;
    Set<T> nodes;
    Graph(Set<pair<T, T>> edges) {
        for (auto it = edges.begin(); it != edges.end(); it++) {
            pair<T, T> e = *it;
            adj[e.first].insert(e.second);
            nodes.insert(e.first);
            nodes.insert(e.second);
        }
    }
    Graph() {}
    Graph(istream& is, int lines) {
        this->read(is, lines);
    }
    void add_edge(pair<T, T> edge) {
      adj[edge.first].insert(edge.second);
      nodes.insert(edge.first);
      nodes.insert(edge.second);
    }
    void add_edge(T a, T b) {
      adj[a].insert(b);
      nodes.insert(a);
      nodes.insert(b);
    }
    Set<pair<T, T>> edges() {
      Set<pair<T, T>> st;
      for (pair<T, Set<T>> a : adj)
          for (T b : a.second)
              if (!st.contains({b, a.first}))
                  st.insert({a.first, b});
      return st;
    }
    Set<pair<T, T>> directed_edges() {
      Set<pair<T, T>> st;
      for (pair<T, Set<T>> a : adj)
          for (T b : a.second)
              st.insert({a.first, b});
      return st;
    }
    bool is_tree() {
        UnionFind<T> UF (nodes);
        for (auto edge : edges()) {
            if (UF.FIND(edge.first, edge.second))
                return false;
            UF.UNION(edge.first, edge.second);
        }
        return true;
    }
    map<T, T> bfs_tree(T root) {
        map<T, T> tree;
        Set<T> vis;
        queue<T> Q;
        vis.insert(root);
        Q.push(root);
        while (!Q.empty()) {
            T u = Q.front();
            Q.pop();
            for (T v : adj[u]) {
                if (!vis.contains(v)) {
                    vis.insert(v);
                    tree[v] = u;
                    Q.push(v);
                }
            }
        }
        return tree;
    }
    bool connected(T start, T target) {
        map<T, T> tree = bfs_tree(start);
        T cur = target;
        for (;;) {
            if (cur == start) return true;
            if (tree.find(cur) == tree.end()) return false;
            cur = tree[cur];
        }
    }
    int min_distance(T start, T target) {
        map<T, T> tree = bfs_tree(start);
        T cur = target;
        int d = 0;
        for (;;) {
            if (cur == start) return d;
            if (tree.find(cur) == tree.end()) return -1;
            cur = tree[cur];
            d++;
        }
    }
    Graph<T> operator+(const Graph<T>& other_graph) {
        Graph<T> new_graph = *this; //copy
        for (pair<T, Set<T>> pr : other_graph.adj) {
            new_graph.adj[pr.first] = new_graph.adj[pr.first] + pr.second;
        }
        return new_graph;
    }
    void read(istream& is, int lines) {
        for (int i = 0; i < lines; i++) {
            int a, b;
            is >> a >> b;
            this->add_edge(a, b);
            this->add_edge(b, a);
        }
    }
};

int main()
{
  int N, M;
  cin >> N >> M;
  Graph<int> G (cin, M);
  cout << (G.is_tree() ? "Good" : "Bad");

  return 0;
}
