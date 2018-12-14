#include <bits/stdc++.h>
using namespace std;

// snippet-begin
// dep:string
template <class T>
struct Set {
    // A general set data structure that depends only on STL
    set<T> s;
    Set(set<T> _s) {
        this->s = _s;
    }
    Set() {}
    void insert(T e) { this->s.insert(e); }
    void clear() { this->s.clear(); }
    int size() const { return this->s.size(); }
    bool empty() const { return this->s.empty(); }
    void remove(T e) { this->s.erase(this->s.find(e)); }
    typename set<T>::iterator begin() const { return this->s.begin(); }
    typename set<T>::iterator end() const { return this->s.end(); }
    Set<T> operator+(const Set<T>& other) {
        Set nw = this->s;
        for (T e : other.s) nw.insert(e);
        return nw;
    }
    bool contains (T e) const {
        return (s.find(e) != s.end());
    }
    Set<T>& operator+=(const Set<T>& other) {
        for (T e : other.s) this->s.insert(e);
        return *this;
    }
    bool operator<(const Set<T>& other) const {
        return this->s < other.s;
    }
    Set<T> operator&(const Set<T>& other) const {
        Set<T> nw;
        for (T e : other) if (this->contains(e)) nw.insert(e);
        return nw;
    }
};

/*
 * Returns a string for a generic Set<T>.
 */
template <class T>
string to_string(Set<T> m) {
    return to_string(m.s);
}

Set<int> rng(int a, int b) {
    Set<int> k;
    for (int i = a; i < b; i++) k.insert(i);
    return k;
}
Set<int> rng(int a, int b, int c) {
    Set<int> k;
    for (int i = a; i < b; i+=c) k.insert(i);
    return k;
}
// snippet-end

int main()
{
    set<pair<int, int>> st;
    st.insert({1, 2});
    st.insert({2, 3});
    st.insert({3, 4});
    st.insert({4, 5});
    st.insert({5, 6});
    st.insert({6, 7});
    Graph G (st);
    map<int, int> tree = G.bfs_tree(1);
    for (pair<int, int> edge : tree) printf("(%d, %d)\n", edge.first, edge.second);
    return 0;
}
