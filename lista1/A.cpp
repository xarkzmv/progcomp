#include <bits/stdc++.h>
using namespace std;

int main () {
    
    int n,k;
    vector <int> positions;
    
    cin >> n >> k;

    positions.push_back(0);
    int i = 0;

    while(k > i) {
        string p;
        cin >> p; //thrown
        
        if(p == "undo") {
            int m;
            cin >> m;

            for(int j = 0; j < m; j++){
                if(positions.size() > 1) positions.pop_back();
            }

        } else {
            int _p = stoi(p); // string to int
            int position = (positions.back() + _p) % n;

            if(position < 0) position += n;
            positions.push_back(position);

        }   

        i++;
    }

    cout << positions.back() << endl;
    return 0;
}