#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

template <class T>
class SegTree {
public:
    vector<T> Tree, Lazy; T Flag; function<T(T,T,int)> Op; int Size;
    SegTree(function<T(T,T,int)> _Op, T _Flag, vector<T>& Initial_Values) {
        Op = _Op; Flag = _Flag; Size = Initial_Values.size();
        Tree.resize(Size*4, Flag); Lazy.resize(Size*4, Flag);
        for (int i = 0; i < Size; i++)
            Modify(0, 0, Size-1, i, i, Initial_Values[i]);
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
        Push(node, st, en);
        if (st > en || en < left || right < st) return;
        if (left <= st && en <= right) {
            Lazy[node] = Op(Lazy[node], value, 1);
            Push(node, st, en);
            return;
        }
        Modify(node*2+1, st, (st+en)/2, left, right, value);
        Modify(node*2+2, (st+en)/2+1, en, left, right, value);
        Tree[node] = Op(Tree[node*2+1], Tree[node*2+2], 1);
    }
    T Query(int node, int st, int en, int left, int right) {
        Push(node, st, en);
        if (st > en || en < left || right < st) return Flag;
        if (left <= st && en <= right) return Tree[node];
        T p1 = Query(node*2+1, st, (st+en)/2, left, right);
        T p2 = Query(node*2+2, (st+en)/2+1, en, left, right);
        return Op(p1, p2, 1);
    }
};

const int MAXN = 1e5+1;
int N;
vector<int> A;

void Solve()
{
    cin >> N;
    A = vector<int>(N);
    FOR(i, 0, N) cin >> A[i];
    auto tr = SegTree<int>([](int a, int b, int k){return a|b;}, 0, A);
    int mx = -1, id = 0;
    FOR(i, 0, N) {
        int l = i-1 >= 0 ? tr.Query(0, 0, N-1, 0, i-1) : 0;
        int r = i+1 <= N-1 ? tr.Query(0, 0, N-1, i+1, N-1) : 0;
        int k = l | r;
        int p = (A[i]|k)-k;
        if (p > mx) {
            mx = p;
            id = i;
        }
    }
    cout << A[id] << ' ';
    FOR(i, 0, N) if (i != id) cout << A[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

