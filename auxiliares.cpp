#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

bool esMatriz(tablero t){
    bool res = true;
    for(int i = 0; i<t.size(); i++){
        if(t.size() != t[i].size()){
            res = false;
        }
    }
    return res;
}

bool casillasValidas(tablero t){
    bool res = true;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size(); j++){
            if (t[i][j].first < 1 && t[i][j].first > 4
                && t[i][j].second < 1 && t[i][j].second > 2
                || (t[i][j].first == 0 && t[i][j].second ==0)){
                res = false;
            }
        }
    }
    return res;
}

int aparicionesEnTablero(tablero t, casilla c){
    int suma = 0;
    for(int i = 0; i<t.size(); i++){
        for(int j = 0; j<t[i].size(); j++){
            if(t[i][j] == c){
                suma++;
            }
        }
    }
    return suma;
}

bool cantidadValidaDePiezas(tablero t){
    bool res = false;
    res = aparicionesEnTablero(t, make_pair (4,1)) == 1
            && aparicionesEnTablero(t, make_pair (4,2)) == 1;

    return res;
}

bool esTableroValido(tablero t){
    bool res = true;
    res = esMatriz(t) && casillasValidas(t);
    return res;
}