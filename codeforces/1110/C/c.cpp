#include <bits/stdc++.h>
using namespace std;

int q;

int solve(int a) {
    int k = 1;
    while (k < a) k=k<<1|1;
    if (k == a) {
        for (int i=2; i*i<a; i++)
            if (a%i==0)
                return a/i;
        return 1;
    } else {
        return k;
    }
}

int main()
{
    cin >> q;
    while (q--){
        int a; cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}

// 10, 01 -> (11, 00) = 3
// 11, 01 -> (10, 01) = 1
// 101, 010 -> (111, 000) = 111
// 1111, 1110 -> (0001, 1110)
// Another way to phrase problem:
// What two numbers less than a, have opposite
// bits and have maximal GCD?
// Let k be the first int one less than a power of 2 (all 1's)
// greater than or equal to a.
// Then, if k > a, answer is k^a.
// This guarantees a^b is largest possible and a&b is 0.
// If k == a, then
// gcd(a^b,a&b)=gcd((2**x-1)^b,(2**x-1)&b)=gcd(2**x-1-b,b)=gcd(2**x-1,b)
//   =gcd(a,b). So answer must be largest value that divides a (max b).
// 111, 101 -> (010, 101) coprime
// 001/010/011/100/101/110
// 110/101/100/011/010/001
// 1   1   1   1   1   1
// 0001/0010/0011/0100/0101/0110/1001/1010/1011/1100/1101/1110
// 1110/1101/1100/1011/1010/1001/0110/0101/0100/0011/0010/0001
// 1    1    3    1    5    3    3    5    1    3    1    1
