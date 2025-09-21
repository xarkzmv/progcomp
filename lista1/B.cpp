#include <bits/stdc++.h>
using namespace std;

int main () {

    int N = 0;
    
    cin >> N;
    vector <int> A;


    // O (n) 
    // y buscar el elemento mas grande
    int first = -1; 
    int second = -1;
    int first_i = 0;
    int second_i = 0;

    int H;
    for(int i = 0; i < N; i++){

        cin >> H;

        if(first == -1) {
            first = H;
            first_i = i;
        }
        else if(first < H) {
            second = first;
            second_i = first_i;
            first = H;
            first_i = i;
        }
        else if(first > H && second < H) {
            second = H;
            second_i = i;
        }
        
        A.push_back(H); 
        

        //seleccionar la mas grande y la segunda mas grande. 
    };

    int height = second;

    //cortar el vector y obtener el menor

    int min = 0;
    if(first_i > second_i) min = *min_element(A.begin() + second_i, A.begin() + first_i);
    else min = *min_element(A.begin()+ first_i, A.begin() + second_i);

    int jump = height - min;

    cout << jump;
    cout <<"\n";
    
    return 0;
}

//1.obtener el mas grande y todos los segundos, los segundos se guardan en una pila
//2. entre el inicio hasta el final de los sub arreglos, obtener el numero menor de cada uno
//3. una vez obtenido el menor. necesitamos calcular la altura. 

//hay que obtener el salto más grande. 