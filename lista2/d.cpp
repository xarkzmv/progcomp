#include <bits/stdc++.h>
using namespace std;

int main () {

    string line;
    getline(cin,line);
    vector <string> attributes;

    //split de la linea por espacios
    size_t pos = 0;
    while((pos = line.find(' ')) != string ::npos){
        attributes.push_back(line.substr(0,pos));
        line.erase(0, pos+1);
    }
    attributes.push_back(line); // 

    int m;
    cin >> m;
    vector<vector<string>> songs(m);
     for (int i = 0; i < m; i++) {
        getline(cin, line);
        vector<string> song;
        size_t pos = 0;
        string token;
        while ((pos = line.find(' ')) != string::npos) {
            token = line.substr(0, pos);
            song.push_back(token);
            line.erase(0, pos + 1);
        }
        song.push_back(line);
        songs[i] = song;
    }

    for (int i =0 ; i < songs.size(); i++) {
        for(int j = 0; j < songs[i].size(); j++) {
            cout << songs[i][j];
        }
    }
    return 0;
}