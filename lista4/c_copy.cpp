#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long 

void solve() {
    ll l, d; // largo, distancia mínima
    int n;    // pájaros ya sentados
    cin >> l >> d >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // 1. Caso especial: No hay pájaros existentes (n=0)
    if (n == 0) {
        // La longitud total utilizable es de 6 a l-6.
        ll usable_length = l - 12; 
        
        // Si no hay espacio, la respuesta es 0.
        if (usable_length < 0) {
            cout << 0 << endl;
            return;
        }
        
        // El número de pájaros es: (Longitud utilizable / d) + 1 (para el primer pájaro en la posición 6)
        ll max_total_birds = (usable_length / d) + 1;
        cout << max_total_birds << endl;
        return;
    }

    // 2. Pájaros existentes (n > 0)
    // Ordenar las posiciones es esencial para analizar los espacios.
    sort(p.begin(), p.end());

    ll total_adicional = 0;

    // --- Espacio 1: Inicio (de la posición 6 a p[0]) ---
    // El primer pájaro que puede ir es en 6. El siguiente en 6+d, etc.
    ll dist_inicio = p[0] - 6;
    if (dist_inicio > 0) {
        // El número de segmentos de longitud 'd' que caben, incluyendo el primer pájaro en 6.
        total_adicional += (dist_inicio / d); 
    }

    // --- Espacio 2: Intermedios (entre p[i] y p[i+1]) ---
    for (int i = 0; i < n - 1; i++) {
        ll dist_intermedia = p[i + 1] - p[i];
        
        // La distancia debe ser >= d (esto está garantizado en la entrada).
        // Queremos saber cuántos pájaros caben *adicionalmente* al que está en p[i].
        // (dist / d) es el número de segmentos, y debe haber al menos 2 (2d de distancia) para un nuevo pájaro.
        // Restamos 1 porque p[i] ya está ocupado.
        if (dist_intermedia >= 2 * d) {
             total_adicional += (dist_intermedia / d) - 1;
        }
    }

    // --- Espacio 3: Final (de p[n-1] a l-6) ---
    // El último pájaro puede ir en l-6. El anterior en l-6-d, etc.
    ll final_limit = l - 6;
    ll dist_final = final_limit - p[n - 1];

    if (dist_final > 0) {
        // Similar al inicio, contamos cuántos segmentos de 'd' caben
        // a partir de la posición p[n-1], incluyendo el último pájaro en l-6.
        total_adicional += (dist_final / d);
    }
    
    cout << total_adicional << endl;
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}