#include <bits/stdc++.h>

using namespace std;

int main () {
    string x;
    cin >> x;

    int nx;
    bool finded = false; 

    int i =x.size() -2;
    while(i >= 0 && x[i] >= x[i+1]) {
        i--;
    }
    if(i < 0) {
        cout << 0 << endl;
        return 0;
    }

    // tomaremos el ultimo respecto al primer digito. 
    int j = x.size() - 1;
    while (x[j] <= x[i]) {
        j--;
    }
   
    swap(x[i],x[j]);

    // invertir la parte derecha (desde i'hata el final)
    reverse(x.begin() + i + 1, x.end());
    cout <<x << endl;
    return 0;

}