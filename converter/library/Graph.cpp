// snippet-begin
template <class T, class W>
class Graph {
    // A general explicit graph data structure
    // Defaults to an unweighted, undirected, explicit graph.
    //
    // Graph Classifications:
    // 
    // Weighted / Unweighted
    // Directed / Undirected
public:
    map<T, Set<T>> adj;
    Set<T> nodes;
    map<pair<T, T>, W> weights;
    bool weighted = false, 
         directed = false;
    Graph(Set<pair<T, T>> edges) {
        for (auto it = edges.begin(); it != edges.end(); it++) {
            pair<T, T> e = *it;
            adj[e.first].insert(e.second);
            nodes.insert(e.first);
            nodes.insert(e.second);
        }
    }
    Graph() {}
    Graph(set<string> opts) {
        if (opts.find("weighted") != opts.end())
            this->weighted = true;
        if (opts.find("unweighted") != opts.end())
            this->weighted = false;
        if (opts.find("directed") != opts.end())
            this->directed = true;
        if (opts.find("undirected") != opts.end())
            this->directed = false;
    }
    Graph(istream& is, int lines) {
        this->read(is, lines);
    }
    void add_edge(pair<T, T> edge) {
        nodes.insert(edge.first);
        nodes.insert(edge.second);
        adj[edge.first].insert(edge.second);
        if (!this->directed)
            adj[edge.second].insert(edge.first);
    }
    void add_edge(T a, T b) {
        nodes.insert(a);
        nodes.insert(b);
        adj[a].insert(b);
        if (!this->directed)
            adj[b].insert(a);
    }
    void add_edge(T a, T b, W weight) {
        this->add_edge(a, b);
        this->weights[make_pair(a, b)] = weight;
        if (!this->directed)
            this->weights[make_pair(a, b)] = weight;
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
    bool has_cycle() {
        return this->is_tree();
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
    W djikstras(T start, T target) {
        if (!this->weighted) {
            printf("djikstras is only supported on weighted graphs");
            abort();
        }
        printf("not implemented");
        abort();
    }
    int min_distance(T start, T target) {
        // disregards weights
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
    Graph<T, W> operator+(const Graph<T, W>& other_graph) {
        Graph<T, W> new_graph = *this; //copy
        for (pair<T, Set<T>> pr : other_graph.adj) {
            new_graph.adj[pr.first] = new_graph.adj[pr.first] + pr.second;
        }
        return new_graph;
    }
    void read(istream& is, int lines) {
        for (int i = 0; i < lines; i++) {
            int a, b, w;
            if (this->weighted) is >> a >> b >> w;
            else is >> a >> b;
            this->add_edge(a, b);
            if (this->weighted)
                this->weights[make_pair(a, b)] = w;
            if (!this->directed) {
                this->add_edge(b, a);
                if (this->weighted)
                    this->weights[make_pair(b, a)] = w;
            }
        }
    }
};
// snippet-end

