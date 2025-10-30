#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    long long m;

    cin >> n;
    cin >> m; // minutos de inactividad después de los cuales una estación se bloquea automaticamente

    vector <pair<int, int>> estaciones;

    for(int i = 0; i < n; i++) {
        int a; //arrives
        int s; // stay
        cin >> a >> s;
        estaciones.push_back({a,s});
    }

    sort(estaciones.begin(), estaciones.end());

    int unlocked = 0;
    int n_blocks = 0; 
    int counter = 0;

    multiset <long long> freeEnds; // tiempos en los que estaciones se quedaron libres (end a + s)
    int saved = 0;

    for(const auto& est : estaciones) {
        int a = est.first; // arrives
        int s = est.second; // stay

        // cout << "a: " << a  << " vs unlock: "<< unlocked << endl; 

        //buscamos el primer end >= a - m;
        auto it = freeEnds.lower_bound(a - m);
        if(it != freeEnds.end() && *it <= a) {
            ++saved;
            freeEnds.erase(it);
        }

        freeEnds.insert(a+s);
    }
    cout << saved << endl;
    return 0;
}