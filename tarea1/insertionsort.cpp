#include <bits/stdc++.h>
using namespace std;


//leo hasta encontrar un numero menor al anterior, 
//si encuentro uno menor, lo muevo atras, si sigue siendo menor lo sigo posicionando. 

vector <int> insertionSort ( vector <int> v ) {
    int size = v.size();

    for(int i = 1; i < size; i++){
        int j = i; 
        while(j > 0 && v[j-1] > v[j]){
            //swap
            int aux = v[j];
            v[j] = v[j-1]; 
            v[j-1] = aux;
            j--;
        }
    }

    return  v;
}


int main () {
    vector <int> nums = {4, 10, 15, 22, 6, 20, 21, 2, 11, 1, 18, 19, 5, 29, 26, 16, 23, 9, 25, 8, 14, 30, 12, 13, 24, 27, 17, 28, 3, 7};

    insertionSort(nums);

    for ( auto x : nums ) cout << "" << x << " ";
    cout << "\n";
    
    return 0;
}