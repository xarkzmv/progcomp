#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    
    vector<int> moves;
    
    for(int i = 0; i < p; i++) {
        int case_id;
        cin >> case_id;
        
        vector<int> heights;
        for(int j = 0; j < 20; j++) {
            int height;
            cin >> height;
            heights.push_back(height);
        }
        
        // Contar movimientos usando ORDEN ASCENDENTE
        int move_count = 0;
        vector<int> ordered;
        
        for(int j = 0; j < 20; j++) {
            int current = heights[j];
            int pos = ordered.size();
            
            // Encontrar la posición correcta para insertar (ORDEN ASCENDENTE)
            for(int k = 0; k < ordered.size(); k++) {
                if(current < ordered[k]) {  // ¡CAMBIADO A MENOR QUE!
                    pos = k;
                    break;
                }
            }
            
            // Los movimientos son los estudiantes que tiene que pasar
            move_count += ordered.size() - pos;
            
            // Insertar en la posición correcta
            ordered.insert(ordered.begin() + pos, current);
        }
        
        moves.push_back(move_count);
    }
    
    // Imprimir la salida
    for(int i = 0; i < moves.size(); i++) {
        cout << i + 1 << " " << moves[i] << endl;
    }
    
    return 0;
}