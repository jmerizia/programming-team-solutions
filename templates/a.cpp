#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define ALL(x) x.begin(),x.end()
#define DO(i, a, b) for(int i=(a);i<(b);i++)
string join(vector<int> v, string del) {
    string s;
    DO(i, 0, v.size()) s+=(i>0?del:"")+to_string(v[i]);
    return s;
}

template <class T>
void CHART(vector<T> X, vector<T> Y) {
    assert(X.size() == Y.size());
    string d;
    for (int i = 0; i < X.size(); i++) d += to_string(X[i]) + " " + to_string(Y[i]) + "\n";
    string cmd = "echo \"" + d + "\" | gnuplot -p -e \"plot '/dev/stdin' with lines\"";
    system(cmd.c_str());
}
template <class T>
void CHART(function<T(T)> func, T left, T right, int samples) {
    assert(left < right);
    vector<T> X (samples), Y (samples);
    T step = (right - left) / samples;
    T x = left;
    for (int i = 0; i < samples; i++) {
        X[i] = x;
        Y[i] = func(x);
        x += step;
    }
    string d;
    DO(i, 0, X.size()) d += to_string(X[i]) + " " + to_string(Y[i]) + "\n";
    string cmd = "echo \"" + d + "\" | gnuplot -p -e \"plot '/dev/stdin' with lines\"";
    system(cmd.c_str());
}

void Solve()
{
    CHART<double>([](double k){ return tan(k); }, 0.0, 4*M_PI, 100);
    //int n = 11;
    //vector<double> a;
    //double d = 0.0;
    //double step = 0.1;
    //while (d < n) a.push_back(d+=step);
    //vector<double> b (a.size());
    //DO(i, 0, a.size()) {
    //    b[i] = tan(a[i]);
    //}
    //CHART(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

