#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; 
        cin >> N;

        vector<string> colors(N);
        for (int i = 0; i < N; ++i) cin >> colors[i];

        // Mapa color -> índice (0 es el más preferido)
        unordered_map<string,int> id;
        id.reserve(N * 2);
        for (int i = 0; i < N; ++i) id[colors[i]] = i;

        int M; 
        cin >> M;
        vector<vector<char>> bad(N, vector<char>(N, 0));
        for (int k = 0; k < M; ++k) {
            string a, b; 
            cin >> a >> b;
            int i = id[a], j = id[b];
            bad[i][j] = bad[j][i] = 1; // prohibición es simétrica (adyacencia)
        }

        const int FULL = (1 << N) - 1;

        // DP memo[last][mask] = #formas de completar usando 'mask' ya usado y terminando en 'last'
        // last en [0..N-1]
        vector<vector<int>> memo(N, vector<int>(1 << N, -1));

        function<int(int,int)> ways = [&](int last, int mask) -> int {
            if (mask == FULL) return 1;
            int &res = memo[last][mask];
            if (res != -1) return res;
            long long acc = 0;
            for (int nxt = 0; nxt < N; ++nxt) {
                if (!(mask & (1 << nxt)) && !bad[last][nxt]) {
                    acc += ways(nxt, mask | (1 << nxt));
                }
            }
            // Enunciado garantiza < 100000 total, cabe en int
            return res = (int)acc;
        };

        // 1) Conteo total de pinturas válidas
        long long total = 0;
        for (int start = 0; start < N; ++start) {
            total += ways(start, 1 << start);
        }

        // 2) Construir la pintura favorita (greedy + comprobación de completitud con DP)
        vector<int> fav;
        int used = 0;
        for (int pos = 0; pos < N; ++pos) {
            for (int c = 0; c < N; ++c) { // orden de preferencia (0..N-1)
                if (used & (1 << c)) continue;
                if (!fav.empty()) {
                    int last = fav.back();
                    if (bad[last][c]) continue; // haría horrorosa la pintura parcial
                }
                // probar si hay al menos una forma de completar
                int mask_after = used | (1 << c);
                bool feasible = false;
                if (mask_after == FULL) {
                    feasible = true; // ya está completa
                } else {
                    // Necesitamos que desde 'c' con 'mask_after' existan completions
                    feasible = (ways(c, mask_after) > 0);
                }
                if (feasible) {
                    fav.push_back(c);
                    used = mask_after;
                    break; // elige el más preferido factible
                }
            }
        }

        // Salida
        cout << total << "\n";
        for (int i = 0; i < N; ++i) {
            if (i) cout << ' ';
            cout << colors[fav[i]];
        }
        cout << "\n";
    }
    return 0;
}
