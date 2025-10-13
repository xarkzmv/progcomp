#include <bits/stdc++.h>
using namespace std;

static inline bool isVowel(char ch) {
    return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    // dp[v][c][hasL]: número de formas hasta la posición actual
    // v = # de vocales consecutivas (0..2), c = # consonantes consecutivas (0..2)
    // Nota: en estados válidos, o v>0 o c>0, pero permitimos (0,0) solo al inicio.
    unsigned long long dp[3][3][2] = {};
    dp[0][0][0] = 1ULL;

    for (char ch : s) {
        unsigned long long ndp[3][3][2] = {};
        auto add = [&](int nv, int nc, int hasL, unsigned long long ways) {
            if (nv <= 2 && nc <= 2) ndp[nv][nc][hasL] += ways;
        };

        for (int v=0; v<=2; ++v) for (int c=0; c<=2; ++c) for (int hasL=0; hasL<=1; ++hasL) {
            unsigned long long cur = dp[v][c][hasL];
            if (!cur) continue;

            if (ch == '_') {
                // 1) Poner una vocal (5 opciones)
                if (v+1 <= 2) add(v+1, 0, hasL, cur * 5ULL);

                // 2) Poner consonante no 'L' (20 opciones)
                if (c+1 <= 2) add(0, c+1, hasL, cur * 20ULL);

                // 3) Poner 'L' (1 opción, activa la condición de tener L)
                if (c+1 <= 2) add(0, c+1, 1, cur * 1ULL);

            } else if (isVowel(ch)) {
                // Letra fija vocal
                if (v+1 <= 2) add(v+1, 0, hasL, cur);

            } else {
                // Letra fija consonante
                int newHasL = hasL || (ch == 'L');
                if (c+1 <= 2) add(0, c+1, newHasL, cur);
            }
        }
        // mover ndp a dp
        for (int v=0; v<=2; ++v) for (int c=0; c<=2; ++c) for (int hasL=0; hasL<=1; ++hasL)
            dp[v][c][hasL] = ndp[v][c][hasL];
    }

    unsigned long long ans = 0;
    for (int v=0; v<=2; ++v) for (int c=0; c<=2; ++c)
        ans += dp[v][c][1];  // solo los que contienen al menos una 'L'

    cout << ans << "\n";
    return 0;
}
