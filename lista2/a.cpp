#include <bits/stdc++.h>
using namespace std;

int main () {

    const int N = 20;
    int p;
    cin >> p;

    //guardar
    vector <vector <int>> sets;
    vector <int> moves;
    // vector <int> moves (p,0) ;

    
    while(p--){

        vector <int> heights (N);
        int move_count = 0;
        //hay que insertar a los estudiantes en la lista primero. 

        // for(int i = 0; i < N; i++){
        //     int height;
        //     cin >> height;
        //     heights.push_back(height);
        // }

        for(int i = 0; i < N; i++){
            //metemos el estudiante en el arreglo. 
            // int height = heights[i];
            int height;
            cin >> height;
            bool inserted = false;
            
            for(int j = 0; j < heights.size(); j++){
                if( height > heights[j]){
                    //insertamos el elemento en la lista de alturas
                    heights.insert(heights.begin()+j, height);
                    // heights.erase(heights.begin()+i);
                    //hay que calcular los movimientos.
                    move_count += heights.size() - j - 1;
                    inserted = true;
                    break;
                }
            }
            if(!inserted) {
                heights.push_back(height);
            }
            
        }
        sets.push_back(heights);
        moves.push_back(move_count);
    }

    //imprimir la salida
    for(int i = 0; i < moves.size(); i++) {
        cout << i + 1 << " " << moves[i] << endl;
    }
    
    return 0;
}






// cout << "j: " << j <<" - h:" << heights.size() << endl; 
// if(heights[k] < heights[j]){
//     heights.insert(heights.begin() + j, heights[k++]);
//     //calcular el numero de movimientos
//     moves += heights.size() - j;
//     j = 0;
// }
// else {
//     continue;
// }