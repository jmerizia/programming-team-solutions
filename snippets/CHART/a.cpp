#include <bits/stdc++.h>
using namespace std;

//snippet-begin
template <class T>
void CHART(T Yst, T Yen) {
    string d;
    int i = 0;
    for (T it = Yst; it != Yen; it++) {
        d += to_string(i) + " " + to_string(*it) + "\n";
        i++;
    }
    string cmd = "echo \"" + d + \
                  "\" | gnuplot -p -e " + \
                  "\"set style fill solid; " + \
                  "set boxwidth 0.5; " + \
                  "unset key; " + \
                  "plot '/dev/stdin' with boxes \"";
    system(cmd.c_str());
}
//snippet-end

int main()
{
    return 0;
}
