template,string,Set,Graph,UnionFind

int main()
{
  int N, M;
  cin >> N >> M;
  Graph<int> G (cin, M);
  UnionFind<int> UF (rng(1, N+1));
  for (auto edge : G.edges()) {
    if (UF.FIND(edge.first, edge.second)) {
      cout << "Bad";
      return 0;
    }
    UF.UNION(edge.first, edge.second);
  }
  cout << "Good";

  return 0;
}
