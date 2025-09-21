#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    vector <string> words;
    vector <string> new_words;

    while(cin >> s) words.push_back(s);

    //eliminamos los repetidos
    
    //sort(words.begin(), words.end());
    //words.erase(unique(words.begin(), words.end()), words.end()); 
    
    //unique reacomoda los elementos, y los repetidos "van al final", 
    //erase elimina desde el nuevo arreglo hasta el final. 

    //new_words.reserve((size_t)w.size() * (size_t)min<size_t>(w.size(),64));

    int N = words.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) if (i != j) {
            new_words.push_back(words[i] + words[j]);
        }
    }


    // cout << "size: " << N << endl;
    //unique necesita que esten ordenados los elementos para detectar si estan duplicados. 
    sort(new_words.begin(), new_words.end());
    new_words.erase(unique(new_words.begin(),new_words.end()), new_words.end());

    for(int i = 0; i < new_words.size(); i++){
        cout << new_words[i] << endl;
    }

    //obtener las palabras, 
    //hacer las combinaciones
    //ordenar

    return 0;
}