template,Set,Graph,UnionFind,string

// note this doesn't use new syntax:
class Node {
    int val = 0;
    public:
        Node(int val_) {
            val = val_;
        }
};

int main()
    int V, E, start, target
    READ V E start target
    Edges (int) edges // Edges is a macro
    DO (i, 0, E)
        int a, b
        READ a b
        edges.insert({a, b})
    Graph<int> G (edges)
    PRINT (G.connected(start, target) ? "YES\n" : "NO\n")
    Edges (int) e1, e2
    e1.insert({1, 2})
    e1.insert({3, 4})
    e2.insert({2, 3})
    Graph<int> G1 (e1)
    Graph<int> G2 (e2)
    Graph<int> G3 = G1 + G2
    PRINTLN G.connected(1, 4)
