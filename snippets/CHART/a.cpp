#include <bits/stdc++.h>
using namespace std;

//snippet-begin
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
    for(int i = 0; i < X.size(); i++) d += to_string(X[i]) + " " + to_string(Y[i]) + "\n";
    string cmd = "echo \"" + d + "\" | gnuplot -p -e \"plot '/dev/stdin' with lines\"";
    system(cmd.c_str());
}
//snippet-end

int main()
{
    return 0;
}
