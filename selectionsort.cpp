#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n-1; i++) {
        // Encontrar el mínimo elemento en el arreglo no ordenado
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                cout << "<";
            }
        }
        
        // Intercambiar el mínimo elemento encontrado con el primer elemento
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11,0};
    
    cout << "Arreglo original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    selectionSort(arr);
    
    cout << "Arreglo ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}