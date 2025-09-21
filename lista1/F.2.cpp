#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; //number of obstacles. 
    int Y; // how many obstacles mario said he's found on his practice run. 
    long long k; // 0-N
    int obstacles = 0;

    if (!(cin >> N >> Y)) return 0;
    vector <char> counted (N,0); // el (tamaño, valor inicial de los elem)
    
    for(int i = 0; i < Y; i++){
        cin >> k;
        if (0 <= k && k < N && !counted[k]) {
            counted[k] = 1;
            ++obstacles;
        }
    }


    for(int i=0; i < N; ++i){
        if(counted[i] == 0) cout << i << endl;
    }

    cout << "Mario got " << obstacles << " of the dangerous obstacles.\n";
    return 0;
}