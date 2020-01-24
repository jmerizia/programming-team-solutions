#include <bits/stdc++.h>

using namespace std;


vector<string> missingWords(string line1, string line2)
{
    vector<string> s, t;
    istringstream st1 (line1), st2 (line2);
    string a, b;
    while (st1 >> a) s.push_back(a);
    while (st2 >> b) t.push_back(b);

    int idx = 0;
    vector<string> ans;
    for (string word : s) {
        if (idx < t.size() && word == t[idx]) {
            idx++;
        } else {
            ans.push_back(word);
        }
    }
    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    vector<string> res = missingWords(s, t);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
