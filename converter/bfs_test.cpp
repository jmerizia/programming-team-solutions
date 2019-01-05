template,string,Set,Graph,fast_math

int main()
{
  int N, E, S, B;
  cin >> N >> E >> S >> B;
  Graph<int> G;
  G.read(cin, E);
  int d = G.min_distance(S, B);
  printf("%d %d\n", ceil_div(d, 6), d);

  return 0;
}
