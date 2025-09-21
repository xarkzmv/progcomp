#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // Leer los nombres de los atributos
    string line;
    getline(cin, line);
    vector<string> attributes;
    // Split de la línea por espacios
    size_t pos = 0;
    // string::npos : Es una constante especial de la clase std::string en c++
    // Es el valor que devuelve una función de std::string cuando no encuentra lo que buscabas
    
    //Entonces, mientras encuentres elementos con ' '. Cortas la línea y lo agregas en atributos
    while ((pos = line.find(' ')) != string::npos) {
        attributes.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    attributes.push_back(line); // Último atributo


    int m;
    cin >> m;


    //Reglas: 
    // Solo necesitas cin.ignore() cuando vas de cin >> a getline()
    // No necesitas cin.ignore() cuando vas de cin >> a otro cin >>
    // No necesitas cin.ignore() cuando vas de getline() a cin >>


    //Cuando usas cin >> m, lees numeros enteros, pero dejas el salto de linea \n en el buffer de entrada
    // por tanto en el siguiente getline, lo leeria ocmo una cadena vacía
    // por tanto necesitamos agregarlo para no tener problemas. 
    cin.ignore(); // Ignorar el salto de línea después del entero

    vector<vector<string>> songs(m);
    for (int i = 0; i < m; i++) {
        //leemos la linea
        getline(cin, line);
        //obtenemos la cancion
        vector<string> song;
        size_t pos = 0;
        string token;
        while ((pos = line.find(' ')) != string::npos) {
            token = line.substr(0, pos);
            song.push_back(token);
            line.erase(0, pos + 1);
        }
        song.push_back(line);
        songs[i] = song;
    }

    //haremos 3 ordenados segun las categorias
    int n;
    cin >> n;
    cin.ignore(); // Ignorar el salto de línea

    // Vector para almacenar los comandos de ordenamiento
    vector<string> commands(n);
    for (int i = 0; i < n; i++) {
        getline(cin, commands[i]);
    }

    // Para cada comando, ordenar establemente por el atributo indicado
    // con const string&, hacemos referencia a cada cmd de commands sin modificarlo, y sin duplicarlo. 
    for (const string& cmd : commands) {
        // Encontrar el índice del atributo en el vector 'attributes'
        int index = -1;
        for (int i = 0; i < attributes.size(); i++) {
            if (attributes[i] == cmd) {
                index = i;
                break;
            }
        }

        // Ordenar establemente por el atributo en la posición 'index'
        //primero se define el rango a ordenar. 
        //[index](...){...} es un lambda, es una funcion de comparacion
        // index es la variable externa que se captura para decidir por cual columna ordenar
        stable_sort(songs.begin(), songs.end(), 
            [index](const vector<string>& a, const vector<string>& b) {
                return a[index] < b[index];
            });

        // Imprimir la lista de atributos
        for (int i = 0; i < attributes.size(); i++) {
            if (i > 0) cout << " ";
            cout << attributes[i];
        }
        cout << endl;

        // Imprimir las canciones ordenadas
        for (const auto& song : songs) {
            for (int i = 0; i < song.size(); i++) {
                if (i > 0) cout << " ";
                cout << song[i];
            }
            cout << endl;
        }

        // Imprimir línea en blanco entre cada lista
        cout << endl;
    }

    return 0;
}