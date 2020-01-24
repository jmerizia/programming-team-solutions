#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int n = 1000 * 1000;
bool is_prime[n];
vector<int> primes;
const int K = 5000;
ll mem[K][K];

void init()
{
    for (int i = 2; i < n; i++) is_prime[i] = 1;
    for (int i = 2; i*i <= n; i++)
        for (int p = i*i; p < n; p += i)
            is_prime[p] = 0;
    for (int i = 2; i < n; i++) if (is_prime[i]) primes.push_back(i);
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            mem[i][j] = -1;
}

int dp(int a, int b)
{
    if (a == 0) return 1;
    if (mem[a][b] != -1) return mem[a][b];
    ll sm = 0;
    for (int j = 0; primes[j] <= min(a, b); j++) {
        sm += dp(a - primes[j], primes[j]);
    }
    mem[a][b] = sm;
    return sm;
}

int main()
{
    init();
    // dp[0] = 1;
    // for (int i = 1; i <= 10; i++) {
    //     int sm = 0;
    //     for (int j = 0; primes[j] <= i; j++) {
    //         sm += dp[i - primes[j]];
    //     }
    //     dp[i] = sm;
    // }
    for (int i = 0; i < 2000; i++) {
        if (dp(i, i) > 5000) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
