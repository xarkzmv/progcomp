

#include <iostream>
using namespace std;
#include <vector>

int main()
{

    vector <int> list = {7,0,3,10,5,8,6};
    vector <int> ordenado = {};
    int j = 0; 

    // int mayor = 0;
    for(int i = 0; i < list.size(); i++){
        if (i = 0) ordenado[0] = list[i]; //iniciamos el primer elemento de la lista ordenada
        else if(list[i] > ordenado[j]){
            j++;
            ordenado[j] = list[i];
        } 
        else {
            int mayor = ordenado[j];
            ordenado[j] = list[i];
            j++;
            ordenado[j] = mayor;
        }
    }
    return 0;
}