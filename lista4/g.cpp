#include <bits/stdc++.h>
// #define ll long long
using namespace std;
// #define int long long 


int main () {
    // N circular plots 
    // M circular houses and K square houses. 

    int N; int M; int K;
    cin >> N >> M >> K;

    vector <pair<int, bool>> rp; // radio del i plot y si está o no ocupado
    for(int i = 0; i < N ; i++ ){ 
        int r; cin >>r; 
        rp.push_back({r, false});
    }


    vector <int> rc(M); // radio de la i casa
    for(int i = 0; i < M ; i++ ){ 
        cin >> rc[i];
    }
    
    //ordenamos por si acaso

    vector <int> s(K); // largo de la i casa cuadrada
    for(int i = 0; i < K; i++ ){ 
        cin >> s[i];
    }
    
    
    //      Constraints 
    // Only one house on each plot
    // a house cannot touch the boundary of the plot
    
    //Se ordena para no tener que recorrer todo el arreglo
    sort(rp.begin(), rp.end());
    sort(rc.begin(), rc.end());
    sort(s.begin(), s.end());

    int m = 0;
    int k = 0;
    int n_plots = 0;
    for(int i = 0; i < N; i++){

        if(m < M && rc[m] < rp[i].first && !rp[i].second){
            rp[i].second = true;
            m++;
            n_plots++;
            continue;
        }
        if(k < K && !rp[i].second){
            double diagonal = s[k] * sqrt(2);
            if(diagonal <= 2* rp[i].first){
                rp[i].second = true;
                k++;
                n_plots++;
                continue;
            }
        }
    }
    cout << n_plots << endl;
    return 0;
}