#include <bits/stdc++.h>
using namespace std;

// snippet-begin
template <class InputType, class OutputType>
InputType BinarySearch (function<OutputType(InputType)> f, OutputType target, InputType a, InputType b, int iters) {
    // A general binary search algorithm
    InputType l = a, r = b, mid;
    for (int i = 0; i < iters; i++) {
        mid = (l + r) / 2;
        if (f(mid) <= target) l = mid;
        else r = mid;
    }
    return mid;
};
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
