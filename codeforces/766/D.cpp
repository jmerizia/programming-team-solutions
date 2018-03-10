// plz dont tle
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e5+10;
int n, m, q;
pair<int, int> dsu[N];
map<string, int> mp;

void init()
{
  for(int i = 0; i < n; i++) dsu[i] = make_pair(i, 1);
}

// 0: no assoc, 1: syn, 2: ant
int FIND(int a, int b) 
{
  int leader_a = a;
  int leader_b = b;
  int assoc_a = 1; // association with its leader
  int assoc_b = 1;
  while (leader_a != dsu[leader_a].first) {
    assoc_a ^= !dsu[leader_a].second;
    leader_a = dsu[leader_a].first;
  }
  while (leader_b != dsu[leader_b].first) {
    assoc_b ^= !dsu[leader_b].second;
    leader_b = dsu[leader_b].first;
  }
  // compression
  int cur_a = a;
  int cur_b = b;
  int comp_assoc_a = assoc_a;
  int comp_assoc_b = assoc_b;
  int prev_assoc_a = 1;
  int prev_assoc_b = 1;
  while (cur_a != dsu[cur_a].first) {
    // make cur_a point to leader, mindful of association
    pair<int, int> pr = dsu[cur_a];
    comp_assoc_a ^= !prev_assoc_a;
    dsu[cur_a] = make_pair(leader_a, comp_assoc_a);
    prev_assoc_a = pr.second;
    cur_a = pr.first;
  }
  while (cur_b != dsu[cur_b].first) {
    pair<int, int> pr = dsu[cur_b];
    comp_assoc_b ^= !prev_assoc_b;
    dsu[cur_b] = make_pair(leader_b, comp_assoc_b);
    prev_assoc_b = pr.second;
    cur_b = pr.first;
  }
  // end compression
  if (leader_a != leader_b) return 3;
  else {
    if (assoc_a == assoc_b) return 1;
    else return 2;
  }
}

int UNION(int a, int b, int assoc)
{
  // MUST BE DISJOINT
  // make (leader of b) child of (leader of a)
  // and careful of association
  int leader_a = a;
  int leader_b = b;
  assoc = (assoc == 1);
  while (leader_a != dsu[leader_a].first){
    assoc ^= !dsu[leader_a].second;
    leader_a = dsu[leader_a].first;
  }
  while (leader_b != dsu[leader_b].first) {
    assoc ^= !dsu[leader_b].second;
    leader_b = dsu[leader_b].first;
  }
  dsu[leader_b] = make_pair(leader_a, assoc);
}

int main()
{
  cin >> n >> m >> q;
  string wd;
  for(int i = 0; i < n; i++){
    cin >> wd;
    mp[wd] = i;
  }
  init();
  for (int i = 0; i < m; i++) {
    int k; string aa, bb;
    cin >> k >> aa >> bb;
    int a = mp[aa];
    int b = mp[bb];
    int assoc = FIND(a, b);
    if (assoc == 3) {
      // modification needed
      UNION(a, b, k);
      cout << "YES"; 
    } else {
      // no modification
      if (k == assoc) cout << "YES";
      else cout << "NO";
    }
    cout << endl;
    //for (int j = 0; j < n; j++)
    //  cout << dsu[j].first  << ',' << dsu[j].second << ' ';
    //cout << endl;
  }

  for (int i = 0; i < q; i++) {
    string aa, bb;
    cin >> aa >> bb;
    int a = mp[aa];
    int b = mp[bb];
    cout << FIND(a, b) << endl;
    //for (int j = 0; j < n; j++)
    //  cout << dsu[j].first  << ',' << dsu[j].second << ' ';
    //cout << endl;
  }

  //int mx_pth = -1;
  //for (int i = 0; i < n; i++) {
  //  int cur = i;
  //  int cur_pth = 0;
  //  while (cur != dsu[cur].first){
  //    cur = dsu[cur].first;
  //    cur_pth++;
  //  }
  //  mx_pth = max(mx_pth, cur_pth);
  //}
  //cout << "max path: " << mx_pth << endl;

  return 0;
}
