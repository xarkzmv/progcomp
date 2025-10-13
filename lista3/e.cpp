#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Rect {
    int h;
    int w;


    int area() const { return h*w; }
    // Función para rotar el rectángulo (intercambiar alto y ancho)
    Rect rot() const {
        return {w, h};
    }

};

bool canFormSquare(vector<Rect> a) {
    int A = a[0].area(); + a[1].area(); + a[2].area();
    double raiz = sqrt(A); 
    if(raiz * raiz != A){
        return false;
    }

    // Función auxiliar para verificar una configuración específica
    vector <int> p = {0,1,2};
    do {
       
        for(int mask = 0; mask < 8; ++mask) {
            Rect r[3];
            for(int i = 0; i < 3  ; ++i) {
                Rect cur = a[p[i]];
                r[i] = (mask & ())
            }
        }
    }
    auto checkConfiguration = [&](const Rect& r1, const Rect& r2, const Rect& r3) -> bool {


    }

}

int main () {

    vector <Rect> v;
    int sum_x = 0;
    int sum_y = 0;
    bool flag;


    for(int i = 0; i < 3; i++){
        Rect rect; // >=
        int w;
        int h;
        cin >> h;
        cin >> w;

        sum_x+=w;
        sum_y+=h;
        
        rect.h = h;
        rect.w = w;
        rect.area = h*w;
        v.push_back(rect);
    }


    //vamos a verificar mediante el area, si es que su suma da un cuadrado
    int areaTotal = v[0].area + v[1].area + v[2].area;
    double raiz = sqrt(areaTotal); 
    if(raiz * raiz != areaTotal){
        flag = false;
    }

    else {

        // caso1 2 lados tienen la misma altura. o ancho
        //encontrar el mas largo, 
        
        if((v[0].h == v[1].h || v[0].h == v[2].h || v[1].h == v[2].h)){
            //la suma de los dos iguales en altura debe ser lo mismo que la del mas largo
            int i_max = 0;
            for(int i = 0; i < 3; i++) {
                if (v[i].h >= v[i_max].h) i_max = i;
            }
            //teniendo la altura del mas largo
            //debemos comprobar que la altura de los dos mas cortos sumen lo mismo que el largo de este
            int a;// el lado del cuadrado
            if(i_max = 0) {
                a = v[0].h; 
                flag = (v[0].h == (v[1].h + v[2].h)) && ((v[1].w + v[0].w) == a);
                cout << "flag1" << flag;
            } else if( i_max = 1) {
                a = v[1].h; 
                flag = (v[1].h == (v[0].h + v[2].h)) && ((v[1].w + v[0].w) == a);
                cout << "flag2" << flag;
            
            } else if (i_max = 2) {
                a = v[2].h; 
                flag = (v[2].h == (v[1].h + v[0].h)) && ((v[2].w + v[0].w) == a);
                cout << "flag3" << flag;
         
            }
        }

        else if((v[0].w == v[1].w || v[0].w == v[2].w || v[1].w == v[2].w)){
            //la suma de los dos iguales en altura debe ser lo mismo que la del mas largo
            int i_max = 0;
            for(int i = 0; i < 3; i++) {
                if (v[i].w >= v[i_max].w) i_max = i;
            }
            //teniendo la altura del mas largo
            //debemos comprobar que la altura de los dos mas cortos sumen lo mismo que el largo de este
            int a;// el lado del cuadrado
            if(i_max = 0) {
                a = v[0].w; 
                flag = (v[0].w == (v[1].w + v[2].w)) && ((v[1].w + v[0].w) == a);
            } else if( i_max = 1) {
                a = v[1].w; 
                flag = (v[1].w == (v[0].w + v[2].w)) && ((v[1].w + v[0].w) == a);
            } else if (i_max = 2) {
                a = v[2].w; 
                flag = (v[2].w == (v[1].w + v[0].w)) && ((v[2].w + v[0].w) == a);
            }
        }


    }
    if(flag){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}