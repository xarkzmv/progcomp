#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;

    while(cin >> n && n!=0){


        vector<int> list1(n);
        vector<int> list2(n);

        for (int i = 0; i < n; i++) {
            cin >> list1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> list2[i];
        }
        

        vector<int> sorted1 = list1;
        sort(sorted1.begin(), sorted1.end());
        vector<int> sorted2 = list2;
        sort(sorted2.begin(), sorted2.end());


        for(int i = 0; i < n; i++){
            int x = list1[i];
            int pos = lower_bound(sorted1.begin(),sorted1.end(), x) - sorted1.begin();
            cout << sorted2[pos] << endl;
        }

        // for (int i = 0; i < n; i++) {
        //     int x = list1[i];
        //     int pos = lower_bound(sorted1.begin(), sorted1.end(), x) - sorted1.begin();
        //     cout << sorted2[pos] << endl;
        // }
    }
    return 0;
}