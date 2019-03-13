#define LOCAL 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define CONTAINS(set, x) (set.find(x) != set.end())
class Visual { public:
    virtual string vis() = 0;
};
class Context : public Visual { public: vector<Visual *> list;
    Context() {} void add(Visual * v) { list.push_back(v); }
    string vis() {
        string s = "Context(";
        for (int i = 0; i < list.size(); i++)
            s += (i > 0 ? "," : "") + list[i]->vis();
        s += ")";
        return s; } };
class Server { public: Context * c; Server(Context * _c) { c = _c; }
    void step() { cout << c->vis() << endl; /* sends c.vis() and awaits response (blocking) */ }
    void send(string s) { cout << s << endl; /* sends string s to frontend and waits */ }
};


class Structure : public Visual { public:
    // maintains a single value
    int v;
    Structure(int _v) {v = _v;}
    void increment() {v++;}
    void decrement() {v--;}
    string vis() { return "Circle(" + to_string(v) + ")"; }
};

void Solve()
{
    Context c;
    Server SERV (&c);
    Structure a (10); c.add(&a);
    Structure b (20); c.add(&b);
    SERV.step();
    while (a.v < b.v) {
        a.increment();
        SERV.step();
        b.decrement();
        SERV.step();
    }
    SERV.send(to_string(a.v) + ' ' + to_string(b.v));
    cout << c.vis();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
