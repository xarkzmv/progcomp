#include <bits/stdc++.h>
// #define ll long long
using namespace std;
#define int long long 

signed main () {

    int n; cin >> n;
    vector <int> v (n);

    for(int i = 0; i < n; i++) 
        cin >> v[i];
    
    sort(v.begin(), v.end(), greater<int>());

    int sum = 0; 
    for (int i = 0; i < n; i++)
        if((i+1) % 3 == 0)
            sum += v[i];

    cout << sum << endl;
}