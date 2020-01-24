#include <bits/stdc++.h>
using namespace std;

const int n = 1000 * 1000;
int K = 0;
bool is_prime[n];

void init()
{
    for (int i = 2; i < n; i++) is_prime[i] = 1;
    for (int i = 2; i < n; i++) {
        for (int p = 2*i; p < n; p += i) {
            is_prime[p] = 0;
        }
    }
}

int set_i_to(int k, int i, int d)
{
    int x = k;
    int res = 0;
    int c = 0;
    while (x > 0) {
        K++;
        //res *= 10;
        int v;
        if (c == i) {
            v = d;
        } else {
            v = (x % 10);
        }
        res += v * (int)pow(10, c);
        x /= 10;
        c++;
    }
    return res;
}

int count_digits(int a)
{
    int i = 0;
    int x = a;
    while (x > 0) {
        x /= 10;
        i++;
    }
    return i;
}

void solve()
{
    for (int prime = 2; prime < 999999; prime++) {
        if (is_prime[prime]) {
            int num_digits = count_digits(prime);
            for (int bm = 1; bm < (1 << num_digits) - 1; bm++) {
                int cnt = 0;
                //vector<int> values;
                for (int d = 0; d < 10; d++) {
                    if (d == 0 && bm & (1 << (num_digits-1))) { // never set leading digit to 0
                        // i hate this
                        continue;
                    }
                    int p = prime;
                    // modify p -> set all high bits in bm to digit d
                    int x = bm;
                    int i = 0;
                    while (x > 0) {
                        if (x & 1) {
                            p = set_i_to(p, i, d);
                        }
                        x >>= 1;
                        i++;
                    }
                    if (is_prime[p]) {
                        //values.push_back(p);
                        cnt++;
                    }
                }
                if (cnt >= 8) {
                    cout << prime << endl;
                    //cout << prime << ' ' << bm << endl;
                    //for (int idx = 0; idx < cnt; idx++) {
                    //    cout << values[idx] << ' ';
                    //}
                    //cout << endl;
                    cout << "Did approximately " << K << " basic integer operations" << endl;
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    cout << "running sieve..." << endl;
    init();
    cout << "running solution..." << endl;
    solve();
    return 0;
}
