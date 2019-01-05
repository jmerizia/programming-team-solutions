template,string,Set,UnionFind,UndirectedGraph

int main()
{
  int N, M;
  cin >> N >> M;
  UndirectedGraph<int> G (cin, M);
  cout << (G.is_tree() ? "Good" : "Bad");

  return 0;
}
