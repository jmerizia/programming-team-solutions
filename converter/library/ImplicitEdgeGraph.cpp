#include <bits/stdc++.h>
using namespace std;

// snippet-begin
// dep:
template <class T>
struct ImplicitEdgeGraph {
    // A general implicit graph class.
    function<bool(T, T)> has_edge;
    ImplicitEdgeGraph(function<bool(T, T)> _has_edge) {
        has_edge = _has_edge;
    }
    Set<Set<T>> disjoint_components(Set<T> nodes) { // O(V)
        Set<T> not_vis = nodes;
        Set<Set<T>> disjoint_sets;
        while (!not_vis.empty()) {
            queue<T> Q;
            T root = *not_vis.begin();
            Set<T> connected_set ({root});
            not_vis.remove(root);
            Q.push(root);
            while (!Q.empty()) {
                T u = Q.front();
                Q.pop();
                for (T v : not_vis) {
                    if (this->has_edge(u, v)) {
                        connected_set.insert(v);
                        not_vis.remove(v);
                        Q.push(v);
                    }
                }
            }
            disjoint_sets.insert(connected_set);
        }
        return disjoint_sets;
    }
};
// snippet-end

int main()
{
    return 0;
}
