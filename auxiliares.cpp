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
            if ((t[i][j].first < 1 && t[i][j].first > 4
                && t[i][j].second < 1 && t[i][j].second > 2)
                && !(t[i][j].first == 0 && t[i][j].second == 0)){
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
    res = aparicionesEnTablero(t, make_pair (4,1)) == 1                     //rey
            && aparicionesEnTablero(t, make_pair (4,2)) == 1                //rey
               && aparicionesEnTablero(t, make_pair (1,1)) <= 8             //peon
                  && aparicionesEnTablero(t, make_pair (1,2)) <= 8          //peon
                    && aparicionesEnTablero(t, make_pair (2,1)) <= 2        //alfil
                        && aparicionesEnTablero(t, make_pair (2,2)) <= 2;   //alfil

    //torre
    res = res && aparicionesEnTablero(t, make_pair (3,1)) <= 2 + (8-aparicionesEnTablero(t, make_pair (1,1)))
            && aparicionesEnTablero(t, make_pair (3,2)) <= 2+ (8-aparicionesEnTablero(t, make_pair (1,2)));

    return res;
}

bool sinPeonesNoCoronados(tablero t){
    bool res = true;
    for(int i = 0; i<t.size(); i += 7){
        for(int j = 0; j<t[i].size(); j++){
            if(t[i][j].first == 1){
                res = false;
            }
        }
    }
    return res;
}

bool esTableroValido(tablero t){
    bool res = true;
    res = esMatriz(t);
    res = res && casillasValidas(t);
    res = res && cantidadValidaDePiezas(t);
    res = res && sinPeonesNoCoronados(t);
    return res;
}

///////ejercicio 3

#define DIM 8
#define jugador int

bool enRango (int x, int m1, int m2) {
    return ( m1 < x && x < m2 ) || ( m2 < x && x < m1 );
}

bool coordenadaEnRango(coordenada c){
    return 0 <= c.first  && c.first < DIM && 0 <= c.second && c.second < DIM ;
}

int abs(int n){
    if(n<0){
        n = -n;
    }
    return n;
}

int apariciones(vector<coordenada> v, coordenada c ){
        int res = 0;
        for(int i =0; i<v.size(); i++){
            if(v[i] == c)
                res++;
        }
        return res;
}

int color(tablero t, coordenada c){
    return t[c.first][c.second].second;
}

bool casillaVacia(tablero t, coordenada c){
    return t[c.first][c.second] == cVACIA;
}

int pieza (tablero t, coordenada c){
    return (t[c.first][c.second]).first;
}

bool movimientoAlfilValido (tablero t,coordenada o, coordenada d) {
    bool res = true;
    for(int x =0; enRango(x, 0, d.first - o.first); x++){
        for(int y = 0; enRango(y, 0, d.second - o.second); y++){
            if(abs(x) == abs(y)){
                res = res && casillaVacia(t, setCoord(o.first + x, o.second + y));
            }
        }
    }
    res = res && (abs(d.first - o.first) == abs(d.second - o.second));
    return res;
}

bool mueveEnHorizontal (coordenada o, coordenada d) {
    return abs(o.first - d.first) == 0 || abs(o.second - d.second) == 1;
}

bool mueveEnDiagonal (coordenada o, coordenada d) {
    return abs(o.first - d.first) == 1 && abs(o.second - d.second) == 1;
}
bool mueveEnVertical (coordenada o, coordenada d) {
    return abs(o.first - d.first) == 1 && abs(o.second - d.second) == 0;
}
bool movimientoReyValido (coordenada o, coordenada d){
    return mueveEnDiagonal(o, d) || mueveEnVertical(o, d) || mueveEnHorizontal(o, d);
}

bool movimientoPeonValido (int color, coordenada o, coordenada d) {
    return d.second == o.second && ((color == BLANCO && d.first == o.first - 1) || (color = NEGRO && d.first == o.first + 1));
}

bool capturaPeonValida ( tablero t, coordenada o, coordenada d) {
    return abs(d.first - o.first) == 1 && ((color(t, o) == BLANCO && d.second == o.second - 1) || (color(t, o) == NEGRO && d.second == o.second + 1));
}

bool movimientoTorreValido (tablero t, coordenada o, coordenada d) {
    bool res = true;
    if(d.second == o.second){
        for(int x=0;enRango(x, o.first, d.first);x++){
            res = res && casillaVacia(t, setCoord(x, o.second));
        }
    }else if(d.first == o.first){
        for(int y=0;enRango(y, o.second, d.second);y++){
            res = res && casillaVacia(t, setCoord(o.first, y));
        }
    }else{
        res= false;
    }
    return res;
}

bool movimientoPiezaValido (tablero t, coordenada o, coordenada d){
    return (pieza(t, o) == PEON && movimientoPeonValido(color(t, o), o, d)) ||
            (pieza(t, o) == ALFIL && movimientoAlfilValido(t, o, d)) ||
             (pieza(t, o) == TORRE && movimientoTorreValido(t, o, d)) ||
              (pieza(t, o) == REY && movimientoReyValido(o, d));
}

bool casillaAtacada (tablero t, coordenada o, coordenada d) {
    return !casillaVacia(t, o) && ((pieza(t, o) != PEON && movimientoPiezaValido(t, o, d)) || (pieza(t, o) != PEON && capturaPeonValida(t, o, d)));
}

bool sonCasillasAtacadas (tablero t, jugador j, vector<coordenada> atacadas) {
    bool res = true;
    for(int x = 0;x < DIM;x++){
          for(int y = 0;y < DIM;y++){
              coordenada c = setCoord(x,y);
              bool atacadaEnTablero = false;
              for(int i =0;i < DIM;i++){
                  for(int j=0;j < DIM;j++){
                      coordenada o = setCoord(i,j);
                      if(c==o && color(t, o) != j && !casillaAtacada(t, o,c)){
                          res = false;
                      }
                  }
              }

              res = res && ( (atacadaEnTablero && (apariciones(atacadas, c) == 1)) || (!atacadaEnTablero && !(apariciones(atacadas, c) == 1)) );
          }
    }
    return res;
}

///////fin ejercicio 3

/*
//ej 4
bool pertenece(vector<coordenada>c,coordenada d){
    bool res= false;
    for(int i=0; i<c.size(); i++){
        if(c[i]==d){
            res= true;
        }
    }
    return res;
}

bool posicionSiguiente (posicion p, posicion q, coordenada o, coordenada d){
    return (posicionesIgualesExceptoEn()&& casillaVacia(q.first,o)&&(esMovimientoValido(p,o,d)))||(esCapturaValida(p,o,d)&&piezaCorrectaEnDestino(p,q,o,d))
}


bool posicionesIgualesExceptoEn (posicion p, posicion q,vector<coordenada> C) {
    bool res=true;
    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++) {
            coordenada c = setCoord(x, y);
            if (!pertenece(C,c)) {
                if (pieza(p.first, c) != pieza(q.first, c) || color(p.first, c) != color(q.first, c)) {
                    res = false;
                }
            }
        }
    }
    return res;
}


bool esMovimientoValido(posicion p, coordenada o, coordenada d){

   return jugador(p)==color(p.first,o) && casillaVacia(p.first,o)=false && casillaVacia(p.first,d)&& movimientoPiezaValido(p.first,o,d));
}


bool esCapturaValida(posicion p, coordenada o,coordenada d){
    return (casillaVacia(p.first,o)=false && casillaVacia(p.first,d)=false && color(p.first,o)!=color(p.first,d)&& casillaAtacada(p.first,o,d))
}


bool piezaCorrectaEnDestino(posicion p, posicion q, coordenada o, coordenada d){
    return( color(p.first,d)=color(q.first,d)&&(enLineaFinalInicial(d)&& pieza(q.first,d)=TORRE)|| enLineaFinal(d)=false&&pieza(q.first,d)=pieza(p.first,o))
}
bool enLineaFinalInicial(coordenada c){
    return (c.first==0 || c.first==DIM-1)
}
*/