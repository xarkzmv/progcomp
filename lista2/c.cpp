#include <bits/stdc++.h>
using namespace std;

struct Persona {
    string nombre;
    vector <int> clase; // 2 = upper, 1 = middle, 0 = lower
};

int mapClass (string token) {
    if(token == "upper") return 2;
    else if(token == "middle") return 1;
    else if(token == "lower") return 0;
    else return -1;
}


bool compararPersonas(const Persona &a, const Persona &b) {
    // Comparar las clases (vector de ints)
    if (a.clase != b.clase) {
        return a.clase > b.clase; // Mayor clase primero
    }
    // Si clases iguales, orden alfabético
    return a.nombre < b.nombre;
}


int main () {

    int T;
    cin >> T;


    while(T--){

        
        int n; 
        cin >> n;
        cin.ignore(); // por el salto de linea
        
        vector <Persona> personas;
        
        string person; 
        //int maxlen = -1;
        
        for(int i = 0; i < n; i++) {
            
            string line;
            getline(cin , line);
            Persona persona;
            
            size_t n_pos = line.find(':');
            persona.nombre = line.substr(0, n_pos); 
            // string nombre = line.substr(0, n_pos); 
            
            string clases_str = line.substr(n_pos +2);
            //eliminar class del str
            size_t pos = clases_str.find(" class");
            if(pos != string::npos){
                clases_str = clases_str.substr(0,pos);
            }
            
            // ===== DIVIDIR LAS CLASES POR '-' =====
            
            //creamos un objeto stringstream que toma la cadena clases_str como entrada. 
            stringstream ss(clases_str);
            string token; // para almacenar cada fragmento de la cadena dividida
            
            //getline lee del ss hasta el '-' y almacena lo leído en token
            while (getline(ss, token, '-')) {
                persona.clase.push_back(mapClass(token));
            }
            
            // Invertir y rellenar con 1's (middle)
            reverse(persona.clase.begin(),persona.clase.end());
            while(persona.clase.size() < 10){
                persona.clase.push_back(1);
            }
            
            personas.push_back(persona);
            
        }
        
        // ordenar
        sort(personas.begin(), personas.end(), compararPersonas);
        
        for (const auto &p : personas) {
            cout << p.nombre << endl;
        }
        cout << string(30, '=') << endl;
        
    }
        
    return 0;
}