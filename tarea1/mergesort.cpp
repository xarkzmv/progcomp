#include <bits/stdc++.h>
using namespace std;

vector <int> mergeSort ( vector <int> v ){

    int size = v.size();
    if(size <= 1) return;

    vector <int> izq (v.begin(), v.begin() + size/2);
    vector <int> der (v.begin() + size/2 , v.end());

    mergeSort(izq);
    mergeSort(der);


    //merge 
    int i = 0; int j = 0; int k = 0;
    for (; (j < (int)izq.size() )&& (k < (int)der.size()); i++){
        if(izq[j] < der[k]) 
            v[i] = izq[j++];
        else 
            v[i] = der[k++];
    }

    //Agregar lo que sobra porque es el ultimo elemento mayor
    while (j < (int)izq.size()) v[i++] = izq[j++];
    while (k < (int)der.size()) v[i++] = der[k++];

    return v;
}

int main () {
    vector <int> nums = {4, 10, 15, 22, 6, 20, 21, 2, 11, 1, 18, 19, 5, 29, 26, 16, 23, 9, 25, 8, 14, 30, 12, 13, 24, 27, 17, 28, 3, 7};

    mergeSort(nums);
    for(auto x : nums) cout << x << " ";
    cout << "\n";
}
