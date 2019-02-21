#include <bits/stdc++.h>
using namespace std;

int n;

int solve(int a, int b)
{
    set<int> div;
    for (int i = 2; i*i <= a; i++)
        if (a%i==0)
            div.insert(i);
    int res = a+b;
    for (int x : div)
        res = min(res, a/x+b*x);
    return a+b-res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int dec = -1;
    for (int i = 1; i < n; i++) {
        dec = max(dec, solve(a[i], a[0]));
    }
    int sm = 0;
    for (int i = 0; i < n; i++) sm += a[i];
    cout << sm-dec << endl;

    return 0;
}
