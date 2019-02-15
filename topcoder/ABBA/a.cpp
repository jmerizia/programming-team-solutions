#include <bits/stdc++.h>
using namespace std;

class ABBA {
public:
    string canObtain(string a, string b) {
        if (a.size() > b.size()) {
            return "Impossible";
        }
        while (b.size() != a.size()) {
            int last = b.size()-1;
            if (b[last] == 'B') {
                b.pop_back();
                reverse(b.begin(), b.end());
            } else {
                b.pop_back();
            }
        }
        if (a == b) {
            return "Possible";
        } else {
            return "Impossible";
        }
        return 0;
    }
};
