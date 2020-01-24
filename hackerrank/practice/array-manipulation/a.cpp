#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

template <class T>
class SegTree {
public:
    vector<T> Tree, Lazy; T Flag; function<T(T,T,int)> Op; int Size;
    SegTree(function<T(T,T,int)> _Op, T _Flag, vector<T>& Initial_Values) {
        Op = _Op; Flag = _Flag; Size = Initial_Values.size();
        Tree.resize(Size*4, Flag);
        //Lazy.resize(Size*4, Flag);
        //for (int i = 0; i < Size; i++)
        //    Modify(0, 0, Size-1, i, i, Initial_Values[i]);
    }
    void Push(int node, int st, int en) {
        if (Lazy[node] == Flag) return;
        Tree[node] = Op(Tree[node], Lazy[node], en-st+1);
        if (st != en) {
            Lazy[node*2+1] = Op(Lazy[node*2+1], Lazy[node], 1);
            Lazy[node*2+2] = Op(Lazy[node*2+2], Lazy[node], 1);
        }
        Lazy[node] = Flag;
    }
    void Modify(int node, int st, int en, int left, int right, T value) {
        //Push(node, st, en);
        if (st > en || en < left || right < st) return;
        if (left <= st && en <= right) {
            //Lazy[node] = Op(Lazy[node], value, 1);
            //Push(node, st, en);
            return;
        }
        Modify(node*2+1, st, (st+en)/2, left, right, value);
        Modify(node*2+2, (st+en)/2+1, en, left, right, value);
        Tree[node] = Op(Tree[node*2+1], Tree[node*2+2], 1);
    }
    T Query(int node, int st, int en, int left, int right) {
        //Push(node, st, en);
        if (st > en || en < left || right < st) return Flag;
        if (left <= st && en <= right) return Tree[node];
        T p1 = Query(node*2+1, st, (st+en)/2, left, right);
        T p2 = Query(node*2+2, (st+en)/2+1, en, left, right);
        return Op(p1, p2, 1);
    }
};

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> zeros (n, 0);
    SegTree<ll> S ([](ll a, ll b, int k){ return a + b*k; }, 0, zeros);
    for (int i = 0; i < m; i++) {
        ll a, b, k;
        cin >> a >> b >> k;
        a--;
        b--;
        S.Modify(0, 0, n-1, a, b, k);
    }
    ll mx = -1;
    for (ll j = 0; j < n; j++) {
        mx = max(mx, S.Query(0, 0, n-1, j, j));
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

