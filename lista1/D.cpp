#include <bits/stdc++.h>
using namespace std;

int main () {

    //usar cola y pila
    // 1 2 3 4 5
    // 1 2 3 45
    //imprimir "error" en caso de que "D" se aplique a una lista vacia
    
    int k;
    cin >> k;

    while(k--){

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        //in 

        string p;
        cin >> p;

        int n = 0;
        cin >> n;

        string line;
        deque <int> v;

        cin >> line;
        string num;

        //pasar de string a vector
        for(char c : line) {
            if(isdigit(c)) {
                num +=c;
            } else if (!num.empty()){
                v.push_back(stoi(num));
                num.clear();
            }
        }
        if(!num.empty()) v.push_back(stoi(num));

        //trabajar con vectores
        
        bool rev = 0;
        bool err = 0;
        for(char c : p){
            if(c == 'D'){
                if (!v.empty()) {
                    //eliminar por el frente si es que no está reversa
                    if(!rev) v.pop_front();  // elimina el primero en O(1)
                    else v.pop_back(); // elimina el ultimo si está en reversa
                } else {
                    err = 1;
                    break;
                }
            }
            else if(c == 'R'){
                // reverse(v.begin(), v.end()); No conviene revertir antes, lo haremos al final
                rev = !rev;
            }
        }

        //out
        //error
        // if(err) cout << "error\n";
        
        if (err) {
            cout << "error\n";
            continue;
        }
        
        else {
            cout << "[";
            if(!rev) {
                for (size_t i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i + 1 < v.size()) cout << ",";
                }
            } else {
                for (size_t i = 0; i < v.size(); i++) {
                    cout << v[v.size() - 1 - i];
                    if (i + 1 < v.size()) cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}