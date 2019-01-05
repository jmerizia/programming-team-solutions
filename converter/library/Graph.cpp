#include <bits/stdc++.h>
using namespace std;

// snippet-begin
// dep:string,Set
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
      Set<T> seen;
      queue<T> Q;
      T root = *nodes.begin();
      seen.insert(root);
      Q.push(root);
      while (!Q.empty()) {
        T u = Q.front();
        Q.pop();
        for (T v : adj[u]) {
          if (!seen.contains(v)) {
            seen.insert(v);
            Q.push(v);
          }
        }
      }
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
// snippet-end

int main()
{
    set<pair<int, int>> st;
    st.insert({1, 2});
    st.insert({2, 3});
    st.insert({3, 4});
    st.insert({4, 5});
    st.insert({5, 6});
    st.insert({6, 7});
    Graph G (st);
    map<int, int> tree = G.bfs_tree(1);
    for (pair<int, int> edge : tree) printf("(%d, %d)\n", edge.first, edge.second);
    return 0;
}
