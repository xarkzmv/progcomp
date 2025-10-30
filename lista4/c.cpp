#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main () {
    
    ll l; // el largo de la cuerda
    ll d; //lo que no les gusta centarse de cerca
    int n; // los que ya estan en la cuerda
    cin >> l >> d >> n;

    vector <ll> p (n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    //si no hay pajaros
    if (n == 0) {
        ll usable_length = l - 12; 

        // si no hay espacio, la respuesta es 0.
        if(usable_length < 0 ) {
            cout << 0 << endl;
            return 0;
        }


        ll max_total_birds = (usable_length / d) +1 ;
        cout << max_total_birds << endl;    
        return 0;
    }

    //2. Pájaros existentes (n>0)
    //Ordenar las posiciones para analizar los espacios
    sort(p.begin(), p.end());


    ll total_adicional = 0;

    // Espacio 1 
    ll dist_inicio = p[0] - 6;
    if(dist_inicio > 0) {
        total_adicional += (dist_inicio / d);
    }


    // Espacio 2, los intermedios entre p[i] y p[i+1]

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

    // ESpacio 3 Final de p[n-1] a l-6
    ll final_limit = l - 6;
    ll dist_final = final_limit - p[n - 1];
    if (dist_final > 0) {
            // Similar al inicio, contamos cuántos segmentos de 'd' caben
            // a partir de la posición p[n-1], incluyendo el último pájaro en l-6.
            total_adicional += (dist_final / d);
        }
        
    cout << total_adicional << endl;


    //necesito calcular las distancias entre los pajaros
    // y entre el principio y final de la cuerda

    // ll st = 0;
    // ll final = l;
    // int min = 6;

    // int px = st; // será la posicion actual a analizar
    // for(ll i = 0; i < n; i++) {
    //     ll dist = p[i]-px;
    //     max += int(dist/min);
    //     px = p[i];
    // }


    
    

    //Cual es la cantidad maxima de pajaros que pueden haber?
/*
- - - - - - - - - - - - - - - - - - - - - - - - - - - / 6 -> cant de pajaros 
- - - - - - | - - - - - - x | - - - - - x x x | - - - - - -|- - - - -
- - - - - - | - - - - - - | - - - - - - | - - - - - | - - - - - | - - -  
*/
}