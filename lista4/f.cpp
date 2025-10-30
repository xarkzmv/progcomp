#include <bits/stdc++.h>
using namespace std;
#define ll long long 

/*
 *Description:* Finds sets and merges elements, complexity $O( alpha(n))$. $alpha(10^(600)) approx 4$
 *Status:* Highly tested
*/

/*
  Es muy útil en algoritmo de grafos 
  -> Detectar componentes conexas 
  -> Saber si dos elementos pertenencen al mismo conjunto
  -> Unir Conjuntos. 
*/
struct union_find {

  vector<int> e;

  // e[i] guarda información sobre el elemento i

  union_find(int n) { e.assign(n, -1); } // assign crea un vector de tamaño n, con los valores -1

  //Encuentra el representante de x
  int findSet (int x) { 
    return (e[x] < 0 ? x : e[x] = findSet(e[x]));
  }
  
  //Comprueba si x y y estan en el mismo conjunto 
  bool sameSet (int x, int y) { return findSet(x) == findSet(y); }

  int size (int x) { return -e[findSet(x)]; }
  
  // unionSet(x,y) une los conjuntos que contienen a x y y
  bool unionSet (int x, int y) {
    x = findSet(x), y = findSet(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
  }
};

struct edge {
    ll n1;
    ll n2;
    ll w;
};

bool custom_compare( edge n1 , edge n2){
  if(n1.w < n2.w) return 1;
  else return 0;
}
 
int main (){

    ll n;
    cin >> n;

    bool visited [2500] = {0};
    vector <edge> v;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            ll w;
            cin >> w;
            if( j > i && w != 0){
              v.push_back({i,j,w});
            }
        }
    }
    sort(v.begin(), v.end(), custom_compare);

    ll count = 0;
    union_find sets(n);

    for(edge e : v) {
      if( sets.sameSet(e.n1,e.n2) != true ) {
        cout << e.n1+1 << " " << e.n2+1 << endl;
        sets.unionSet(e.n1, e.n2);
      }
    }

    

    return 0;
}