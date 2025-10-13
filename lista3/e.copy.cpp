#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int h, w;
    int area() const { return h * w; }
    Rect rot() const { return {w, h}; }
};

bool canFormSquare(vector<Rect> a) {
    int A = a[0].area() + a[1].area() + a[2].area();
    int S = (int)floor(sqrt((double)A));
    if (1LL*S*S != A) return false;

    // Prueba todas las permutaciones y rotaciones (8 combinaciones por permutación)
    vector<int> p = {0,1,2};
    do {
         //“Si el bit i de mask está encendido, guarda el rectángulo rotado;
        //de lo contrario, guarda el normal.”
        for (int mask = 0; mask < 8; ++mask) {
            Rect r[3];
            for (int i = 0; i < 3; ++i) {
                Rect cur = a[p[i]];
                //1 << i crea un número donde solo el bit i está encendido.
                    // Si i = 0, 1 << 0 → 0001
                    // Si i = 1, 1 << 1 → 0010
                    // Si i = 2, 1 << 2 → 0100
                //El operador & (And bit a bit) compara cada bit entre mask y 1<<i.
                    //Si el bit i de mask está en 1, el resultado será distinto de 0 -> bit encendido
                    //Si el bit i de mask está en 0, el resultado será 0 -> bit apagado. 
                r[i] = (mask & (1<<i)) ? cur.rot() : cur;
            }

            // Caso 1: Tres tiras (todos comparten un lado S)
            bool strips =
                (r[0].h == S && r[1].h == S && r[2].h == S &&
                 r[0].w + r[1].w + r[2].w == S)
                ||
                (r[0].w == S && r[1].w == S && r[2].w == S &&
                 r[0].h + r[1].h + r[2].h == S);
            if (strips) return true;

            // Caso 2: Uno cruza todo el cuadrado y los otros dos rellenan
            // 2a) r0 cruza horizontalmente: w0 = S; los otros dos comparten altura (S - h0) y sus anchos suman S
            if (r[0].w == S) {
                int remH = S - r[0].h;
                if (remH >= 0 &&
                    r[1].h == remH && r[2].h == remH &&
                    r[1].w + r[2].w == S) return true;
            }
            // 2b) r0 cruza verticalmente: h0 = S; los otros dos comparten ancho (S - w0) y sus alturas suman S
            if (r[0].h == S) {
                int remW = S - r[0].w;
                if (remW >= 0 &&
                    r[1].w == remW && r[2].w == remW &&
                    r[1].h + r[2].h == S) return true;
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Rect> v(3);
    for (int i = 0; i < 3; ++i) {
        cin >> v[i].h >> v[i].w;
        // Puedes normalizar a h >= w si quieres, pero no es necesario porque rotamos
    }

    cout << (canFormSquare(v) ? "YES\n" : "NO\n");
    return 0;
}
