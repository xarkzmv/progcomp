#include <bits/stdc++.h>
using namespace std;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string dummy;
    getline(cin, dummy); // consumir el fin de línea tras T
    while(N--){
        
        string input;
        getline(cin, input);
        
        // cin >> input;
        list<char> word;
        auto ix = word.begin();
        
        
        for (char c : input){
            
            if(c == '<'){ //backspace
                //borrar
                if(ix != word.begin()){ // cuando está al inicio no borra
                    auto toErase = ix;
                    --toErase;
                    ix = word.erase(toErase);
                }
            }
            else if(c == '['){ //home
                ix = word.begin();
            }
            else if(c == ']'){ //end
                ix = word.end();
            }
            else {
                //Cualquier otro carácter (letra, número, espacio)
                //Se inserta en la posición actual del cursor.
                word.insert(ix,c);
            }
        }
        
        
        for(auto c : word) {
            cout << c ;
        }
        cout << endl;
    }

    return 0;
}


  