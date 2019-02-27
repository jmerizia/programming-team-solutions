#include <bits/stdc++.h>
using namespace std;

//snippet-begin
struct DSU {
    vector<int> p;
    vector<int> card;
    DSU(int n) {
        p.resize(n);
        card.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int leader(int a) {
        return p[a] == a ? a : (p[a] = leader(p[a]));
    }
    void unite(int a, int b) {
        int la = leader(a);
        int lb = leader(b);
        if (la != lb) {
            int g1 = card[la] > card[lb] ? la : lb;
            int g2 = card[la] > card[lb] ? lb : la;
            p[g2] = g1;
            card[g1] += card[g2];
        }
    }
};
//snippet-end
