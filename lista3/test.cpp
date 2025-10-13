#include <iostream>
#include <algorithm> // Para next_permutation
#include <vector>

using namespace std;

int main() {
    // Ejemplo con array
    int arr[] = {1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Permutaciones de {1, 2, 3}:" << endl;
    
    // next_permutation genera la siguiente permutación en orden lexicográfico
    // Devuelve false cuando ya no hay más permutaciones

    prev_permutation(arr, arr + n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // do {
    //     for(int i = 0; i < n; i++) {
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // } while(next_permutation(arr, arr + n));
    
    cout << "\n---\n" << endl;
    
    // Ejemplo con vector
    vector<char> letras = {'A', 'B', 'C'};
    
    cout << "Permutaciones de {A, B, C}:" << endl;
    
    do {
        for(char c : letras) {
            cout << c << " ";
        }
        cout << endl;
    } while(next_permutation(letras.begin(), letras.end()));
    
    return 0;
}