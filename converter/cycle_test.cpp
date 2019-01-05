template,string,Set,UnionFind,Graph

int main()
{
  int N, M;
  cin >> N >> M;
  Graph<int, int> G ({"undirected", "unweighted"});
  G.read(cin, M);
  cout << (G.is_tree() ? "Good" : "Bad");

  return 0;
}
