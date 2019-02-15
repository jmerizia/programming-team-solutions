template,Set,UnionFind,Graph,string

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Graph<int, int> G ({"undirected", "weighted"});
    G.read(cin, m);
    auto tree = G.mst();
    cout << to_string(tree);
    return 0;
}
