#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // n = número de latas, m = número de colores

    vector<int> cans;    // Latas disponibles
    vector<int> needs;   // Cantidades necesarias

    // Leer latas disponibles (n latas)
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cans.push_back(t);
    }

    // Leer necesidades (m colores)
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        needs.push_back(t);
    }

    // Ordenar las LATAS disponibles (no las necesidades)
    sort(cans.begin(), cans.end());

    long long total_waste = 0;  // Usar long long para evitar overflow

    for(int i = 0; i < m; i++) {
        // Buscar en las LATAS la más pequeña ≥ necesidad
        auto it = lower_bound(cans.begin(), cans.end(), needs[i]);
        
        // El problema garantiza que siempre habrá lata
        int waste = *it - needs[i];
        total_waste += waste;
    }
    
    cout << total_waste;
    return 0;
}