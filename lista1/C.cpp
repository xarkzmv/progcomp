#include <bits/stdc++.h>
using namespace std;


struct Nodo {
    char c;
    struct Nodo *next;
    struct Nodo *prev;

    Nodo (char valor) : c(valor), prev(nullptr), next(nullptr) {}
};

class ListaEnlazada {
    private: 
        Nodo * head;
        Nodo * tail;
        int size;

    public: 
        //constructor
        ListaEnlazada() : head (nullptr), tail(nullptr), size(0){}

        // Destructor
        ~ListaEnlazada() {
            limpiar();
        }

        void insertarAlInicio(int valor);
        void insertarAlFinal(int valor);
        void eliminar(int valor);
        void limpiar();
        void insertarEnIndice(char valor, int indice);
        bool estaVacia() const { return head == nullptr; };
        int obtenerTamaño() const { return size; }
};

void ListaEnlazada::insertarAlInicio(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    nuevoNodo->next = head;
    head = nuevoNodo;
    
    if (tail == nullptr) { // Si la lista estaba vacía
        tail = nuevoNodo;
    }
    
    size++;
}

// Insertar al final
void ListaEnlazada::insertarAlFinal(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    
    if (estaVacia()) {
        head = nuevoNodo;
        tail = nuevoNodo;
    } else {
        tail->next = nuevoNodo;
        tail = nuevoNodo;
    }
    
    size++;
}

void ListaEnlazada::insertarEnIndice(char valor, int indice) {
    // Validar índice
    if (indice < 0 || indice > size) {
        throw std::out_of_range("Índice fuera de rango");
    }
    
    // Casos especiales
    if (indice == 0) {
        insertarAlInicio(valor);
        return;
    }
    
    if (indice == size) {
        insertarAlFinal(valor);
        return;
    }
    
    // Insertar en medio
    Nodo* nuevoNodo = new Nodo(valor);
    Nodo* actual = head;
    
    // Avanzar hasta la posición anterior al índice deseado
    for (int i = 0; i < indice - 1; i++) {
        actual = actual->next;
    }
    
    // Reorganizar punteros
    nuevoNodo->next = actual->next;
    actual->next = nuevoNodo;
    
    size++;
}

int main () {

    ListaEnlazada lista;
    string input;
    string output;

    cin >> input;
    int ix = 0;

    for (char c : input){
        
        if(c == '<'){ //backspace
            //borrar
            if(ix != 0){ // cuando está al inicio no borra
                // output.pop_back();
                ix--;
            }
        }
        else if(c == '['){ //home
            ix = 0;
        }
        else if(c == ']'){ //end
            ix = output.size();
        }
        else {
            //Cualquier otro carácter (letra, número, espacio)
            //Se inserta en la posición actual del cursor.

            // ListaEnlazada.insertarEnIndice(c,ix);
            // if( ix == -1){
            //     lista.insertarAlInicio(c);
            // }
            // else {
            //     lista.insertarAlFinal(c);
            // }
        }
    }


    return 0;
}


  