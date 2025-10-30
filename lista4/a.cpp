#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int m;
    cin >> n;
    cin >> m;

    vector <int> t(n); //tasks 
    vector <int> l(m); //intervals

    for(int i = 0; i < n; i++) {
        cin >> t[i] ;
    }

    for(int i = 0; i < m; i++) {
        cin >> l[i] ;
    }

    //ordenamos las tareas

    sort(t.begin(), t.end());
    sort(l.begin(), l.end());

    int i = 0;
    int j = 0;  
    int count = 0;
    
    while( i < n && j < m){
        if( t[i] <= l[j] ){
            count ++;
            j++; 
            i++;
        } else j++;
    }

    cout << count << endl;
    return 0;
}