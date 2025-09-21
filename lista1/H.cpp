#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B; 
    if(!(cin >> N >> B)) return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    //para obtener la mitad del subgrupo
    int p = -1;
    for (int i = 0; i < N; ++i) if (A[i] == B) { p = i; break; }

    //seteamos si estan a la izquierda o derecha del pivote
    // x[i] = sign(A[i]-B)
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        if (A[i] > B) x[i] = 1;
        else if (A[i] < B) x[i] = -1;
        else x[i] = 0;
    }

    // contamos balances a la izquierda (incluye vacío con s=0)
    unordered_map<int,long long> cnt;
    long long s = 0;
    cnt[0] = 1; // izquierda vacía
    for (int i = p-1; i >= 0; --i) {
        s += x[i]; 
        cnt[s]++;
    }

    
    // recorrer derecha y sumar coincidencias cnt[-t] (incluye derecha vacía t=0)
    long long ans = 0, t = 0;
    ans += cnt[-t]; // t=0 (solo [p..p])
    for (int i = p+1; i < N; ++i) {
        t += x[i];
        ans += cnt[-t];
    }

    cout << ans << "\n";
    return 0;
}
