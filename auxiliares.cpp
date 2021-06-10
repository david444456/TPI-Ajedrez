#include "definiciones.h"
#include "auxiliares.h"

int DIM = 8;

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

///ejerc 2

bool piezaEnCoordenada(tablero t, coordenada c, int pieza, int color){
    return t[c.first][c.second].first == pieza && t[c.first][c.second].second == color;
}

bool cantidadDePiezasAlInicio(tablero t){
    bool res = false;
    res = aparicionesEnTablero(t, make_pair (TORRE,NEGRO)) == 2                     //torre
          && aparicionesEnTablero(t, make_pair (TORRE,BLANCO)) == 2                //torre
          && aparicionesEnTablero(t, make_pair (PEON,NEGRO)) == 8             //peon
          && aparicionesEnTablero(t, make_pair (PEON,BLANCO)) == 8          //peon
          && aparicionesEnTablero(t, make_pair (ALFIL,NEGRO)) == 2        //alfil
          && aparicionesEnTablero(t, make_pair (ALFIL,BLANCO)) == 2;   //alfil

          return res;
}

bool piezasEnCoordenadas(tablero t){
    bool resp = true;

    //peones
    for(int i = 1; i<DIM; i++){
        if(!piezaEnCoordenada(t, make_pair(1,i), PEON, NEGRO)) resp = false;
        if(!piezaEnCoordenada(t, make_pair(6,i), PEON, BLANCO)) resp = false;
    }

    //torre
    if(!piezaEnCoordenada(t, make_pair(0,0), TORRE, NEGRO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(0,DIM-1), TORRE, NEGRO)) resp = false;

    if(!piezaEnCoordenada(t, make_pair(7,0), TORRE, BLANCO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(DIM-1,DIM-1), TORRE, BLANCO)) resp = false;

    //alfil

    if(!piezaEnCoordenada(t, make_pair(0,2), ALFIL, NEGRO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(0,DIM-3), ALFIL, NEGRO)) resp = false;

    if(!piezaEnCoordenada(t, make_pair(DIM-1,2), ALFIL, BLANCO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(DIM-1,DIM-3), ALFIL, BLANCO)) resp = false;

    //rey
    if(!piezaEnCoordenada(t, make_pair(0,4), REY, NEGRO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(DIM-1,4), REY, BLANCO)) resp = false;

    return resp;
}

//ejer 5

void ObtenerTableroOrdenado(tablero& t){
    //preparo
    vector<int> auxCount(DIM-1, 0);

    vector<vector<int>> colorCount;
    vector<int> maxColor (3, 0);

    for(int i = 0; i< DIM-1; i++){
        colorCount.push_back(maxColor);
    }

    //funcionamiento metodo
    for(int i = 0; i<t.size(); i++){
        //counting
        for(int j = 0; j < t[0].size(); j++){
            if(t[i][j].first != 0){
                auxCount[t[i][j].first]++;
                colorCount[t[i][j].first][t[i][j].second] ++;
            }
        }
        //set
        int aparPieza = 0;
        int aparColor = 1;
        for(int j = 0; j < t[i].size(); j++){
            if(t[i][j].first != 0){
                while(auxCount[aparPieza] <= 0 && aparPieza < DIM){
                    aparPieza++;
                }
                while(colorCount[aparPieza][aparColor] <= 0 && aparColor < 3){
                    aparColor++;
                }
                t[i][j] = make_pair(aparPieza, aparColor);
                auxCount[aparPieza]--;
                colorCount[aparPieza][aparColor]--;
            }
        }
    }
}

///////ejercicio 3

#define jugador int
#define DIM 8

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
    bool b = abs(o.first - d.first) == 0 && abs(o.second - d.second) == 1;
    return abs(o.first - d.first) == 0 && abs(o.second - d.second) == 1;
}

bool mueveEnDiagonal (coordenada o, coordenada d) {
    return abs(o.first - d.first) == 1 && abs(o.second - d.second) == 1;
}
bool mueveEnVertical (coordenada o, coordenada d) {
    bool b=abs(o.first - d.first) == 1 && abs(o.second - d.second) == 0;
    return abs(o.first - d.first) == 1 && abs(o.second - d.second) == 0;
}
bool movimientoReyValido (coordenada o, coordenada d){
    return mueveEnDiagonal(o, d) || mueveEnVertical(o, d) || mueveEnHorizontal(o, d);
}

bool movimientoPeonValido (int color, coordenada o, coordenada d) {
    return d.second == o.second && ((color == BLANCO && d.first == o.first - 1) || (color = NEGRO && d.first == o.first + 1));
}

bool capturaPeonValida ( tablero t, coordenada o, coordenada d) {
    bool ambos  =abs(d.second - o.second) == 1;
    bool blanco = (color(t, o) == BLANCO && d.first == o.first - 1);
    bool negro  = (color(t, o) == NEGRO  && d.first == o.first + 1);
    return ambos && (blanco || negro);
}

/*
 * cambie el indexado arriba, porque esta asi en TPI?
bool capturaPeonValida ( tablero t, coordenada o, coordenada d) {
    bool ambos  =abs(d.first - o.first) == 1;
    bool blanco = (color(t, o) == BLANCO && d.second == o.second - 1);
    bool negro  = (color(t, o) == NEGRO  && d.second == o.second + 1);
    return ambos && (blanco || negro);
}
*/
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
    bool res = (pieza(t, o) == PEON && movimientoPeonValido(color(t, o), o, d)) ||
                    (pieza(t, o) == ALFIL && movimientoAlfilValido(t, o, d)) ||
                        (pieza(t, o) == TORRE && movimientoTorreValido(t, o, d)) ||
                            (pieza(t, o) == REY && movimientoReyValido(o, d));
    return res;
}

bool casillaAtacada (tablero t, coordenada o, coordenada d) {
    bool res = false;

    if(!casillaVacia(t, o) &&
                ((pieza(t, o) != PEON && movimientoPiezaValido(t, o, d))
                        || (pieza(t, o) == PEON && capturaPeonValida(t, o, d))))
        res = true;

   return  res;
}
/*
bool sonCasillasAtacadas (tablero t, jugador j, vector<coordenada> atacadas) {
    bool res = true;
    for(int x = 0;x < DIM;x++){
          for(int y = 0;y < DIM;y++){
              coordenada c = setCoord(x,y);
              bool atacadaEnTablero = false;
              for(int a =0;a < DIM;a++){
                  for(int b=0;b < DIM;b++){
                      coordenada o = setCoord(a,b);
                      if(c!=o  && color(t, o) == j && casillaAtacada(t, o,c)){
                          atacadaEnTablero = true;
                      }
                  }
              }

              res = res && ( (atacadaEnTablero && (apariciones (atacadas,c)== 1)) || (!atacadaEnTablero && !(apariciones (atacadas,c)== 1)) );
          }
    }
    return res;
}
*/
vector<coordenada> obtenerCasillasAtacadas(tablero t,jugador j){

    vector <coordenada> cA;
    for(int x = 0;x < DIM;x++){
        for(int y = 0;y < DIM;y++){
            coordenada c = setCoord(x,y);
            for(int a =0;a < DIM;a++){
                for(int b=0;b < DIM;b++){
                    coordenada o = setCoord(a,b);
                    if( c!=o  && color(t, o) == j && casillaAtacada(t, o,c)){
                        cA.push_back(c);
                    }
                }
            }
        }
    }
    return cA;
}

/*
vector<coordenada> obtenerCasillasAtacadas(tablero t,jugador j){

    vector <coordenada> cA;
    for(int x = 0; x<t.size(); x++){
        for(int y = 0; y<t[x].size(); y++){
            coordenada c = setCoord(x,y);
            for(int a =0; a<t.size();a++){
                for(int b =0; b<t[a].size();b++){
                    coordenada o = setCoord(a,b);
                    if(apariciones(cA,c)==0 && casillaAtacada(t,o,c)
                       && t[o.first][o.second].second == j){
                        cA.push_back(c);
                    }
                }
            }
        }
    }
    return cA;
}
*/

///////fin ejercicio 3


//ej 4

bool enLineaFinalInicial(coordenada c){
    return (c.first==0 || c.first==DIM-1);
}

bool piezaCorrectaEnDestino(posicion p, posicion q, coordenada o, coordenada d){
    return (color(p.first,d)==color(q.first,d)
    && (enLineaFinalInicial(d)
    && pieza(q.first,d)==TORRE)
    || enLineaFinalInicial(d)
    && pieza(q.first,d) == pieza(p.first,o));
}
bool esCapturaValida(posicion p, coordenada o,coordenada d){
    return (casillaVacia(p.first,o)==false && casillaVacia(p.first,d)==false && color(p.first,o)!=color(p.first,d)&& casillaAtacada(p.first,o,d));
}

bool esMovimientoValido(posicion p, coordenada o, coordenada d){

    return p.second == color(p.first,o)
           && casillaVacia(p.first,o)==false
           && casillaVacia(p.first,d)
           && movimientoPiezaValido(p.first,o,d);
}

bool pertenece(vector<coordenada>c,coordenada d){
    bool res= false;
    for(int i=0; i<c.size(); i++){
        if(c[i]==d){
            res= true;
        }
    }
    return res;
}

bool posicionesIgualesExceptoEn (posicion p, posicion q,vector<coordenada> C) {
    bool res = false;
    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++) {
            coordenada c = setCoord(x, y);
            if (!pertenece(C,c)) {
                if (pieza(p.first, c) == pieza(q.first, c) && color(p.first, c) == color(q.first, c)) {
                    res = true;
                }
                res = true;
            }
        }
    }
    return res;
}
bool posicionSiguiente (posicion p, posicion q, coordenada o, coordenada d){
    vector<coordenada> ca;
    ca.push_back(o);
    ca.push_back(d);

    return (posicionesIgualesExceptoEn(p, q, ca)
    && casillaVacia(q.first,o)
    &&(esMovimientoValido(p,o,d)))
    ||(esCapturaValida(p,o,d)
    &&piezaCorrectaEnDestino(p,q,o,d));
}




