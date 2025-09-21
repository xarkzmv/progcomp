#include <bits/stdc++.h>
using namespace std;

int main () {

    int n = 0;
    bool first_case = true;
    while (cin >> n && n != 0){

        if (!first_case) {
            cout << endl;  // Línea en blanco entre casos
        }
        first_case = false;

        vector<string> words (n);
        
        //agregar al vector
        for(int i = 0; i < n; i++){
            cin >> words[i];
        }

        //ordenar hasta la segunda letra
        stable_sort(words.begin(), words.end(), 
            [](const string &a, const string &b){
                string a_prefix = a.substr(0, 2);
                string b_prefix = b.substr(0, 2);
                return a_prefix < b_prefix;
            });

        for( string word : words ) {
            cout << word << endl;
        }
        cout << endl;
    }   

    return 0;
}