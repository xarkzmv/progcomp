#include <bits/stdc++.h>
using namespace std;

static inline void parse_array_line(const string& line, deque<int>& v) {
    // line es algo tipo: [1,2,3] o []
    int num = 0;
    bool in_num = false, neg = false;
    for (char c : line) {
        if (c == '-') { neg = true; }
        else if (isdigit(c)) {
            in_num = true;
            num = num*10 + (c - '0');
        } else {
            if (in_num) {
                v.push_back(neg ? -num : num);
                num = 0; in_num = false; neg = false;
            } else {
                neg = false;
            }
        }
    }
    if (in_num) v.push_back(neg ? -num : num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string p;  cin >> p;   // cadena de operaciones
        int n;      cin >> n;  // cantidad declarada (puede servir para reservar)
        string line;
        // leer la línea del arreglo completa con los corchetes
        cin >> ws;                     // come espacios/nuevas líneas pendientes
        getline(cin, line);            // ahora deberíamos tener algo como "[1,2,3]"
        if (line.empty()) getline(cin, line); // por si había un salto más

        deque<int> v;
        v.clear();
        v.resize(0);
        v.shrink_to_fit();
        v.clear();

        // parsear con seguridad (soporta [] y números negativos)
        parse_array_line(line, v);

        bool err = false;
        bool rev = false;

        for (char c : p) {
            if (c == 'R') {
                rev = !rev;
            } else if (c == 'D') {
                if (v.empty()) {
                    err = true;
                    break;         // no sigas procesando
                }
                if (!rev) v.pop_front();
                else      v.pop_back();
            }
        }

        if (err) {
            cout << "error\n";
            continue;
        }

        // salida en el orden correcto según 'rev'
        cout << "[";
        if (!v.empty()) {
            if (!rev) {
                for (size_t i = 0; i < v.size(); ++i) {
                    if (i) cout << ",";
                    cout << v[i];
                }
            } else {
                for (size_t i = 0; i < v.size(); ++i) {
                    if (i) cout << ",";
                    cout << v[v.size()-1-i];
                }
            }
        }
        cout << "]\n";
    }
    return 0;
}
