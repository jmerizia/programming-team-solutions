#include <bits/stdc++.h>
using namespace std;

const int N = 140000;

class Seg {
    int t[N*2];
    Seg() {
        build();
    }
    void build(vector<int> a) {
        int n = a.size();
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i*2] + t[i*2+1];
    }
};


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a (n);
    for (int i = 0; i < 1<<n; i++) {
        cin >> a[i];
    }

    return 0;
}
