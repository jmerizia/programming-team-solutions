// snippet-begin
template <class T>
class UndirectedGraph {
    // A general directed graph data structure
public:
    map<T, Set<T>> adj;
    Set<T> nodes;
    UndirectedGraph(Set<pair<T, T>> edges) {
        for (auto it = edges.begin(); it != edges.end(); it++) {
            pair<T, T> e = *it;
            adj[e.first].insert(e.second);
            nodes.insert(e.first);
            nodes.insert(e.second);
        }
    }
    UndirectedGraph() {}
    UndirectedGraph(istream& is, int lines) {
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
    UndirectedGraph<T> operator+(const UndirectedGraph<T>& other_graph) {
        UndirectedGraph<T> new_graph = *this; //copy
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

