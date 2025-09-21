#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> diff(H+2, 0); // indices 1 to H

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) { // stalagmite
            diff[1]++; // a partir de la posicion 1, suma 1 a todos los elementos
            diff[a+1]--; // a partir de la posicion a+1, resta 1 a todos los elementos
        } else { // stalactite
            diff[H - a + 1]++;
            // no need to subtract at H+1 because we won't iterate beyond H
        }
    }

    // es no tacion cientifica, un valor muy grande.
    int min_obstacles = 1e9;
    int count = 0;
    int current = 0;
    for (int h=1; h<=H; h++) {
        current += diff[h];
        if (current < min_obstacles) {
            min_obstacles = current;
            count = 1;
        } else if (current == min_obstacles) {
            count++;
        }
    }

    cout << min_obstacles << " " << count << endl;
    return 0;
}