#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
set<ll> squares;

// allow (x, y, z) to represent a cuboid,
// such that x <= y <= z.
// Then the shortest path is
// z^2+(x+y)^2 = z^2+b^2
// Now the problem becomes finding all
// unordered pairs (z, b) such that
// z^2+b^2=n^2 for some integer n.
// Note that since x, y > 0, b > z.
// For any given (z, b) pair,
// we may determine the total number
// of possible x, y values.
// Consider that the smallest value
// y can take on is mn = (b+1)/2,
// and the largest value is
// mx = min(z, b-1).
// So, the size of this range is
// mx-mn+1.

void init()
{
    for (ll i = 1; i <= 100000; i++)
        squares.insert(i*i);
}

bool has_integer_shortest_path_cuboid(int x, int y, int z)
{
    // assumes x <= y <= z
    return squares.count(z*z+(x+y)*(x+y));
}

int phi_slow(int M)
{
    int cnt = 0;
    for (int x = 1; x <= M; x++) {
        for (int y = x; y <= M; y++) {
            for (int z = y; z <= M; z++) {
                if (has_integer_shortest_path_cuboid(x, y, z)) {
                    //cout << x << ' ';
                    //cout << y << ' ';
                    //cout << z << ' ';
                    //cout << endl;
                    cnt += 1;
                }
            }
        }
    }
    return cnt;
}

bool has_integer_shortest_path(int z, int b)
{
    return squares.count(z*z+b*b);
}

int possible_xy(int z, int b)
{
    int mn = (b+1)/2;
    int mx = min(z, b-1);
    int k = mx-mn+1;
    if (k < 0) {
        cout << k << ' ';
        cout << mn << ' ';
        cout << mx << ' ';
        cout << mx << ' ';
    }
    return k;
}

int phi(int M)
{
    int cnt = 0;
    for (int z = 1; z <= M; z++) {
        for (int b = 2; b <= 2*z; b++) {
            if (has_integer_shortest_path(z, b)) {
                int ad = possible_xy(z, b);
                //cout << z << ' ';
                //cout << b << ' ';
                //cout << ad << ' ';
                //cout << endl;
                cnt += ad;
            }
        }
    }
    return cnt;
}

void solve()
{
    // binary search
    int l = 100, r = 1000;
    for (int i = 0; i < 20; i++) {
        int mid = (l+r)/2;
        if (phi(mid) < 1000000) l = mid;
        else r = mid;
    }
}

int main()
{
    init();
    //cout << possible_xy(8, 10, 9) << endl;
    int n1 = 1817;
    int n2 = 1818;
    cout << "fast = " << phi(n1) << endl;
    cout << "fast = " << phi(n2) << endl;
    //cout << "slow = " << phi_slow(n) << endl;
    return 0;
}
