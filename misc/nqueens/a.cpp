#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n;
vector<vector<int>> board;
// 0 - empty
// 1 - covered
// 2 - queen

vector<pii> valid()
{
    vector<pii> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 0)
                v.push_back(make_pair(i, j));
    random_shuffle(v.begin(), v.end());
    return v;
}

void place(pii p) {
    int i, j; tie(i, j) = p;
    for (int o = 0; o < n; o++) board[i][o] = 1, board[o][j] = 1;
    for (int a = i, b = j; a < n && b < n; a++, b++) board[a][b] = 1;
    for (int a = i, b = j; a >= 0 && b >= 0; a--, b--) board[a][b] = 1;
    for (int a = i, b = j; a < n && b >= 0; a++, b--) board[a][b] = 1;
    for (int a = i, b = j; a >= 0 && b < n; a--, b++) board[a][b] = 1;
    board[i][j] = 2;
}

void prt()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (board[i][j] == 2 ? 'Q' : '.') << ' ';
        cout << endl;
    }
}

bool solve(int k)
{
    if (k == n) return true;
    for (pii p : valid()) {
        auto board_ = board;
        place(p);
        if (solve(k + 1)) return true;
        board = board_;
    }
    return false;
}

int main()
{
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        vector<int> v (n);
        board.push_back(v);
    }
    solve(0);
    prt();
}
