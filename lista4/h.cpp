#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {

    int m; cin >> m;

    while(m--){
        int l;
        int n; 
        cin >> l >> n;
        vector <int> vp;
        for(int i = 0; i < n; i++){
            int p; cin >> p;
            vp.push_back(p);
        }

        // sort(vp.begin(), vp.end());

        int min_time = 0, max_time = 0;
        for(int i = 0; i < n; i++) {
            min_time = max(min_time, min(vp[i], l - vp[i]));
            max_time = max(max_time, max(vp[i], l - vp[i]));
        }
        cout << min_time << " " << max_time << endl;
        // size_t medium_ix = (vp.size()-1)/2;
        // int medium = vp[medium_ix];
        // int first = vp[0];
        // int last = vp[n-1];

        // for()

        // //probamos por el lado derecho el calculo del menor
        // int min_t = min (medium, l-medium);

        // //buscamos para el tiempo mas largo
        // int max_t = max(l-first, last);

        // cout << min_t << " " << max_t << endl;
    }


    return 0;
}