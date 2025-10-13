#include <bits/stdc++.h>
// #include <bitset>
using namespace std;

bitset<8> decodificar (bitset<8> b) {
    bitset<8> x;
    // LSB -> MSB: x0 = b0; xi = bi ^ x(i-1)
    x[0] = b[0];
    for (int i = 1; i < 8; ++i) {
        x[i] = b[i] ^ x[i - 1];
    }
    // cout << "original: "<< x << endl;
    return x;
}

int main () {

    int n;
    cin >> n;
    // bitset<8> bin (n);
    //bin.to_ulong(); // entrega el numero decimal

    vector <bitset<8>> bytes;

    for(int i = 0; i < n; i++) {
        int b;
        cin >> b;
        bitset <8> bin(b);
        // cout <<"codificado: " << bin << endl;
        bytes.push_back(bin);
    }
    
    //decodificar. 
    for(int i = 0; i < n; i++) {
        bitset <8> decoded = decodificar(bytes[i]);
        cout << (int)decoded.to_ulong();
        if (i < n-1) cout << " ";

    }
    cout << endl;

    return 0;

}