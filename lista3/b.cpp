#include <bits/stdc++.h>
using namespace std;


int main () {

    pair <int,int> target_positions[256];

    target_positions['A'] = {0, 0};
    target_positions['B'] = {0, 1};
    target_positions['C'] = {0, 2};
    target_positions['D'] = {0, 3};
    target_positions['E'] = {1, 0};
    target_positions['F'] = {1, 1};
    target_positions['G'] = {1, 2};
    target_positions['H'] = {1, 3};
    target_positions['I'] = {2, 0};
    target_positions['J'] = {2, 1};
    target_positions['K'] = {2, 2};
    target_positions['L'] = {2, 3};
    target_positions['M'] = {3, 0};
    target_positions['N'] = {3, 1};
    target_positions['O'] = {3, 2};


    vector<string> puzzle(4);
    for (int i = 0; i < 4; i++) {
        getline(cin, puzzle[i]);
    }
 

    int scatter = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            char letra = puzzle[i][j];
            //buscar la letra en el dicc
            if( letra != '.') {
                pair <int, int> target =  target_positions[letra];
                int distance = abs(i - target.first) + abs(j - target.second);
                scatter += distance;
            }
        }
    }

    cout << scatter << endl;
    return 0;
}