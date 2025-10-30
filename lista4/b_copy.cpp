#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<pair<int, int>> researchers;
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        researchers.push_back({a, s});
    }

    // Ordenar investigadores por tiempo de llegada
    sort(researchers.begin(), researchers.end());

    // Min-heap para almacenar los tiempos en que las estaciones quedan desbloqueadas
    // (fin_uso + m)
    priority_queue<long long, vector<long long>, greater<long long>> unlockedUntil;

    int unlockCount = 0; // Cuántas veces Penelope tuvo que desbloquear

    for (const auto& r : researchers) {
        int a = r.first;  // llega en a
        int s = r.second; // se queda s minutos

        // Liberar estaciones que ya se bloquearon (fin_uso + m < a)
        while (!unlockedUntil.empty() && unlockedUntil.top() < a) {
            unlockedUntil.pop();
        }

        // Verificar si hay alguna estación desbloqueada disponible
        if (!unlockedUntil.empty() && unlockedUntil.top() >= a) {
            // Reusar esta estación (ahorramos un desbloqueo)
            unlockedUntil.pop();
        } else {
            // No hay estación desbloqueada -> necesitamos desbloquear una nueva
            unlockCount++;
        }

        // Esta estación (nueva o reusada) terminará en a + s
        // y quedará desbloqueada hasta (a + s) + m
        unlockedUntil.push(a + s + m);
    }

    // El ahorro es: n - unlockCount
    // (sin optimización: n desbloqueos, con optimización: unlockCount desbloqueos)
    cout << (n - unlockCount) << endl;

    return 0;
}