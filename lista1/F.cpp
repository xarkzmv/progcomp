#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; //number of obstacles. 
    int Y; // how many obstacles mario said he's found on his practice run. 
    long long k; // 0-N

    if (!(cin >> N >> Y)) return 0;
    set <int> counted; // el (tamaño, valor inicial de los elem)
    
    for(int i = 0; i < Y; i++){
        cin >> k;
        if (0 <= k && k < N) counted.insert(k);
    }

    int obstacles = (int)counted.size();

    auto it = counted.begin(); 

    //set <int>::iterator it = counted.begin();

    for(int i=0; i < N; i++){
        if(*it == i) {
            ++it;
        } else cout << i << endl;
            
    }

    cout << "Mario got " << obstacles << " of the dangerous obstacles." << endl;
    return 0;
}