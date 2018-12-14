// snippet-begin
// dep:
string format(string s, vector<string> v);
template <class T> string to_string(pair<T, T> p);
template <class T> string to_string(set<T> m);

/*
 * Takes a string and a vector of strings,
 * replacing each instance of {} with the
 * corresponding vector element.
 */
string format(string s, vector<string> v) {
    string o;
    if (s.size() == 0) return o;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s[i] == '{' && s[i+1] == '}') {
            assert(v.size() != c);
            o += v[c++], i++;
        } else {
            o += s[i];
        }
    }
    return o;
}

/*
 * Returns a string representation of a generic pair<T, T>.
 */
template <class T>
string to_string(pair<T, T> p) {
    return format("({}, {})", {to_string(p.first), to_string(p.second)});
}

/*
 * Returns a string for a generic set<T>.
 */
template <class T>
string to_string(set<T> m) {
    string s = "{";
    int idx = 0, sz = m.size();
    for (T elem : m) {
        s += to_string(elem);
        if (++idx < sz) s += ", ";
    }
    s += "}";
    return s;
}

/*
 * Returns a string for a generic vector<T>.
 */
template <class T>
string to_string(vector<T> m) {
    string s = "{";
    int idx = 0, sz = m.size();
    for (T elem : m) {
        s += to_string(elem);
        if (++idx < sz) s += ", ";
    }
    s += "}";
    return s;
}

/*
 * Returns a string for a generic map<T, T>.
 */
template <class T>
string to_string(map<T, T> m) {
    string s = "{";
    int idx = 0, sz = m.size();
    for (pair<T, T> elem : m) {
        s += to_string(elem);
        if (++idx < sz) s += ", ";
    }
    s += "}";
    return s;
}

// snippet-end
