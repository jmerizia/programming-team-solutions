#include <bits/stdc++.h>
using namespace std;

// snippet-begin
template <class T>
struct UnionFind {
    // A general UnionFind Data Structure
    map<T, T> parent;
    UnionFind(vector<T> items) {
        for (T item : items) parent[item] = item;
    }
    UnionFind(set<T> items) {
        for (T item : items) parent[item] = item;
    }
    T leader(T a) {
        T cur = a;
        while (cur != parent[cur]) cur = parent[cur];
        return cur;
    }
    void compress(T a) {
        T lead = this->leader(a);
        T cur = this->parent[a], prev = a;
        while (cur != parent[cur]) {
            parent[cur] = lead;
            cur = parent[cur];
        }
    }
    void UNION(T a, T b) {
        T leader_a = leader(a);
        T leader_b = leader(b);
        if (leader_a != leader_b) parent[leader_b] = leader_a;
    }
    bool FIND(T a, T b) {
        compress(a);
        compress(b);
        return leader(a) == leader(b);
    }
};
// snippet-end

int main()
{
    return 0;
}
