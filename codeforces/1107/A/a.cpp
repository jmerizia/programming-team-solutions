#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int q;
    cin >> q;
    vector<string> v;
    for (int i = 0; i < q; i++) {
        int k; string s; cin >> k >> s;
        v.push_back(s);
    }

    for (string s : v) {
        if (s.length() == 1) {
            cout << "NO";
        }
        else if (s.length() == 2) {
            if (s[0] >= s[1]) {
                cout << "NO";
            } else {
                cout << "YES" << endl << "2" << endl;
                cout << s[0] << ' ' << s[1];
            }
        } else {
            cout << "YES" << endl << "2" << endl;
            cout << s[0] << ' ';
            for (int i = 1; i < (int)s.length(); i++) {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}
