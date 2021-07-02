#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
/*
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}*/

/// ejercicio 1

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

int contrincante(int j){
    int res= BLANCO;
    if(j==BLANCO){
        res= NEGRO;
    }
    return res;
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

            if ( !(cVACIA == t[i][j] || ( 0 < t[i][j].first && t[i][j].first < 5 && 0 < t[i][j].second && t[i][j].second < 3 ))){
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

///ejercicio 2
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
    for(int i = 1; i<ANCHO_TABLERO; i++){
        if(!piezaEnCoordenada(t, make_pair(1,i), PEON, NEGRO)) resp = false;
        if(!piezaEnCoordenada(t, make_pair(6,i), PEON, BLANCO)) resp = false;
    }

    //torre
    if(!piezaEnCoordenada(t, make_pair(0,0), TORRE, NEGRO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(0,ANCHO_TABLERO-1), TORRE, NEGRO)) resp = false;

    if(!piezaEnCoordenada(t, make_pair(7,0), TORRE, BLANCO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(ANCHO_TABLERO-1,ANCHO_TABLERO-1), TORRE, BLANCO)) resp = false;

    //alfil

    if(!piezaEnCoordenada(t, make_pair(0,2), ALFIL, NEGRO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(0,ANCHO_TABLERO-3), ALFIL, NEGRO)) resp = false;

    if(!piezaEnCoordenada(t, make_pair(ANCHO_TABLERO-1,2), ALFIL, BLANCO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(ANCHO_TABLERO-1,ANCHO_TABLERO-3), ALFIL, BLANCO)) resp = false;

    //rey

    if(!piezaEnCoordenada(t, make_pair(0,4), REY, NEGRO)) resp = false;
    if(!piezaEnCoordenada(t, make_pair(ANCHO_TABLERO-1,4), REY, BLANCO)) resp = false;

    return resp;
}

/// ejercicio 3


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
    for(int x =min(o.first,d.first) + 1; x<max(o.first,d.first); x++){
        for(int y =min(o.second,d.second) + 1; y < max(o.second,d.second); y++){
            coordenada m = setCoord( x,  y);
            if(m==make_pair(6,4)){
                int hola = 1;
            }
            if(abs(m.first - o.first) == abs(m.second - o.second)){

                res = res && casillaVacia(t,m);
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
    return d.second == o.second && ((color == BLANCO && d.first == o.first - 1) || (color == NEGRO && d.first == o.first + 1));
}

bool capturaPeonValida ( tablero t, coordenada o, coordenada d) {
    bool ambos  =abs(d.second - o.second) == 1;
    bool blanco = (color(t, o) == BLANCO && d.first == o.first - 1);
    bool negro  = (color(t, o) == NEGRO  && d.first == o.first + 1);
    return ambos && (blanco || negro);
}

bool movimientoTorreValido (tablero t, coordenada o, coordenada d) {

    bool res = true;
    if(d.second == o.second){ //vertical
        for(int x= min(o.first, d.first)+1;x<max(o.first, d.first);x++){
            res = res && casillaVacia(t, setCoord(x, o.second));
        }
    }else if(d.first == o.first){ //horizontal
        for(int y = min(o.second, d.second)+1;y<max(o.second, d.second);y++){
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

    bool a = !casillaVacia(t, o);
    bool b =(pieza(t, o) != PEON  && movimientoPiezaValido(t, o, d));
    bool c= (pieza(t, o) == PEON  && capturaPeonValida(t, o, d));

    if( a && ( b || c ))
        res = true;

   return  res;
}

vector<coordenada> obtenerCasillasAtacadas(tablero t,int j){
    vector <coordenada> cA;
    for(int x = 0;x < ANCHO_TABLERO;x++){
        for(int y = 0;y < ANCHO_TABLERO;y++){
            coordenada c = setCoord(x,y);
            for(int a =0;a < ANCHO_TABLERO;a++){
                for(int b=0;b < ANCHO_TABLERO;b++){
                    coordenada o = setCoord(a,b);

                    bool pa = (c!=o);
                    bool pb = color(t, o) == j;
                    bool pc = casillaAtacada(t, o,c);
                    bool pd = apariciones(cA,c) == 0;


                    if( pa  && pb && pc && pd){
                        cA.push_back(c);
                    }
                }
            }
        }
    }
    return cA;
}



/// ejercicio 4

bool enLineaFinalInicial(coordenada c){
    return (c.first==0 || c.first==ANCHO_TABLERO-1);
}

bool piezaCorrectaEnDestino(posicion p, posicion q, coordenada o, coordenada d){
    /*
    primera correccion
    bool da = color(p.first,o)==color(q.first,d);
    bool db = enLineaFinalInicial(d);
    bool dc1 = pieza(q.first,d)==TORRE;
    bool dc2 = pieza(p.first,o)==PEON;
    bool de = !enLineaFinalInicial(d);
    bool df = pieza(q.first,d) == pieza(p.first,o);
    return da && ((db && dc1 && dc2) || (de && df));
    */

    /*
    segunda correccion
    bool Color = color(p.first,o)==color(q.first,d);
    bool lineaFinal = enLineaFinalInicial(d);
    bool aTorre = pieza(q.first,d)==TORRE;
    bool peon = pieza(p.first,o)==PEON;
    bool Pieza = pieza(q.first,d) == pieza(p.first,o);

    return Color && ((peon && lineaFinal && aTorre) || (!(peon && lineaFinal) && Pieza));
    */

    return color(p.first,o)==color(q.first,d) && ((pieza(p.first,o)==PEON && enLineaFinalInicial(d) && pieza(q.first,d)==TORRE) || (!(pieza(p.first,o)==PEON && enLineaFinalInicial(d)) && pieza(q.first,d) == pieza(p.first,o)));

}

bool esCapturaValida(posicion p, coordenada o,coordenada d){

    return (casillaVacia(p.first,o)==false
    && casillaVacia(p.first,d)==false
    && color(p.first,o)!=color(p.first,d)
    && casillaAtacada(p.first,o,d));
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
    for (int x = 0; x < ANCHO_TABLERO; x++) {
        for (int y = 0; y < ANCHO_TABLERO; y++) {
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
    /*
    bool posIguales = posicionesIgualesExceptoEn(p, q, ca);
    bool casVacia = casillaVacia(q.first,o);
    bool destinoCorrecto= piezaCorrectaEnDestino(p,q,o,d);

    bool movimientoValido = esMovimientoValido(p,o,d);
    bool capturaValida= esCapturaValida(p,o,d);

    primera version del return
    return (posIguales && casVacia && movimientoValido ) || (capturaValida && destinoCorrecto);
    segunda version del return
    return posIguales && casVacia && (movimientoValido  || capturaValida) && destinoCorrecto;
    */

    return posicionesIgualesExceptoEn(p, q, ca) && casillaVacia(q.first,o) && (esMovimientoValido(p,o,d)  || esCapturaValida(p,o,d)) && piezaCorrectaEnDestino(p,q,o,d);
}

/// ejercicio 5

void ObtenerTableroOrdenado(tablero& t){
    vector<int> auxCount(ANCHO_TABLERO-1, 0);

    vector<vector<int>> colorCount;
    vector<int> maxColor (3, 0);

    for(int i = 0; i< ANCHO_TABLERO-1; i++){
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

        int aparPieza = 0;

        for(int j = 0; j < t[i].size(); j++){
            int aparColor = 1;
            if(t[i][j].first != 0){
                while(auxCount[aparPieza] <= 0 && aparPieza < ANCHO_TABLERO){
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

/// ejercicio 6

posicion seConvierteEnPosicion(posicion p, coordenada o, coordenada d){
    posicion t = p;

    if(t.first[o.first][o.second] == cPEON_B && o.first == 1 && d.first == 0){
        t.first[d.first][d.second] = make_pair(3,1);
    }else if(t.first[o.first][o.second] == cPEON_N && o.first == 6 && d.first == 7){
        t.first[d.first][d.second] = make_pair(3,2);
    }else{
        t.first[d.first][d.second] = p.first[o.first][o.second];
    }

    t.first[o.first][o.second] = make_pair(VACIO,VACIO);
    return t;
}

bool loPoneEnjaque (posicion p, coordenada o, coordenada d){

    posicion q = seConvierteEnPosicion(p,o,d);
    /*
    bool PosicionSiguiente = posicionSiguiente(p,q,o,d);
    bool JugadorEnJaque = jugadorEnJaque(q,p.second);
    bool res = PosicionSiguiente && JugadorEnJaque; //&& p.second==q.second
    return res;
     */

    return posicionSiguiente(p,q,o,d) && jugadorEnJaque(q,p.second);
}

bool esJugadaLegal (posicion p, coordenada o, coordenada d){
    /*
    bool MovimientoValido = esMovimientoValido(p,o,d);
    bool CapturaValida = esCapturaValida(p,o,d);
    bool PoneEnJaque = loPoneEnjaque(p,o,d);
    bool res= ( MovimientoValido || CapturaValida) && !PoneEnJaque;
    return res;
    */

    return ( esMovimientoValido(p,o,d) || esCapturaValida(p,o,d) ) && !loPoneEnjaque(p,o,d) ;
}

bool existeMovimientoParaSalirDelJaque(posicion p){
    bool res = false;
    for(int x = 0;x < ANCHO_TABLERO;x++) {
        for (int y = 0; y < ANCHO_TABLERO; y++) {
            coordenada o = setCoord(x, y);
            for(int i = 0; i<ANCHO_TABLERO;i++){
                for(int j = 0; j<ANCHO_TABLERO;j++){
                    coordenada d = setCoord(i, j);
                    if(color(p.first, o) == p.second && esJugadaLegal(p, o, d)){
                        res = true;
                    }
                }
            }
        }
    }
    return res;
}

bool esJaqueMate(posicion p){
    /*
    bool JugadorEnJaque = jugadorEnJaque(p, p.second);
    bool ExisteUnMovimientoParaSalirDelJaque = existeMovimientoParaSalirDelJaque(p);
    bool res = JugadorEnJaque && !ExisteUnMovimientoParaSalirDelJaque;
    return res;
    */

    return jugadorEnJaque(p, p.second) && !existeMovimientoParaSalirDelJaque(p);
}

bool atacaAlRey (posicion p, coordenada o){
    bool res=false;
    for(int x = 0;x < ANCHO_TABLERO;x++) {
        for (int y = 0; y < ANCHO_TABLERO; y++) {
            coordenada d = setCoord(x,y);
            /*
            bool a =pieza(p.first,d)==REY;
            bool b =color(p.first,d)==p.second;
            bool c = esCapturaValida(p,o,d);
            if(a && b && c){
                res=true;
            }
            */
            if(pieza(p.first,d)==REY && color(p.first,d)==p.second && esCapturaValida(p,o,d)){
                res=true;
            }
        }
    }
    return res;
}

bool jugadorEnJaque (posicion p, int jug) {
    bool res = false;
    posicion q = p;
    q.second = jug;
    for(int i = 0; i<p.first.size();i++){
        for(int j =0; j <p.first[i].size();j++){
            coordenada o = setCoord(i,j);
            /*
            bool da = (color(q.first,o)== contrincante(jug));
            bool db = atacaAlRey(q,o);
            if( da && db){
                res = true;
            }
            */

            if( (color(q.first,o)== contrincante(jug)) && atacaAlRey(q,o)){
                res = true;
            }

        }
    }
    return res;
}

bool noHayMovimientosLegales (posicion p){
    bool res = true;

    for (int i=0; i<p.first.size(); i++){
        for (int j=0; j<p.first[i].size(); j++){
            coordenada o = make_pair(i,j);
            if(p.first[i][j].first != 0){
                for(int a =0; a<p.first.size();a++){
                    for(int b =0; b<p.first[a].size();b++){
                        coordenada d = make_pair(a,b);
                        if( esJugadaLegal(p, o, d)){
                            res = false;
                        }
                    }
                }
            }
        }
    }
    return res;
}

bool soloHayReyes (tablero t){
    bool res=true;
    for(int x = 0;x < ANCHO_TABLERO;x++){
        for(int y = 0;y < ANCHO_TABLERO;y++){
            coordenada c = setCoord(x,y);
                if (!(casillaVacia(t,c) || pieza(t,c) == REY)){
                    res = false;
                }
        }
    }
    return res;
}

bool esEmpate (posicion p){
    /*
    bool a = soloHayReyes(p.first);
    bool c = !jugadorEnJaque(p,p.second);
    bool d = noHayMovimientosLegales(p);

    bool res =  a || (c && d);
    return res;
    */

    return soloHayReyes(p.first) || ( !jugadorEnJaque(p,p.second) && noHayMovimientosLegales(p));
}

/// ejercicio 7

bool jugadorEnJaqueExcluyendoD (posicion p, int jug, coordenada d) {
    bool res = false;
    posicion q = p;
    q.second = jug;
    for(int i = 0; i<p.first.size();i++){
        for(int j =0; j <p.first[i].size();j++){
            coordenada o = setCoord(i, j);
            if( o != d) {
                /*
                bool da = (color(q.first, o) == contrincante(jug));
                bool db = atacaAlRey(q, o);
                if (da && db) {
                    res = true;
                }
                */
                if ( (color(q.first, o) == contrincante(jug)) && atacaAlRey(q, o)) {
                    res = true;
                }

            }
        }
    }
    return res;
}

bool alMoverQuedaEnJaque(posicion p){
    bool res = false;

    for(int i = 0; i<ANCHO_TABLERO;i++){
        for(int j = 0; j < ANCHO_TABLERO; j++){
            coordenada o = make_pair(i,j);
            for(int x = 0; x < ANCHO_TABLERO; x++){
                for(int y = 0; y<ANCHO_TABLERO; y++){
                    coordenada d = setCoord(x,y);

                    posicion q = seConvierteEnPosicion(p, o, d);
                    q.second= contrincante(p.second);

                    if(posicionSiguiente(p, q, o, d) && jugadorEnJaqueExcluyendoD(q, q.second, d)){
                        res= true;
                    }
                }
            }
        }
    }

    return res;
}

/// ejercicio 8

posicion PosicionResultanteUnaJugada(posicion p, coordenada o, coordenada d){
    posicion res = seConvierteEnPosicion(p,o,d);
    res.second = contrincante(p.second);
    return res;
}

vector <coordenada> ObtenerUnicasCoordenadasForzada(posicion p){
    vector <coordenada> movibles;
    for(int i = 0; i<ANCHO_TABLERO;i++){
        for(int j = 0; j < ANCHO_TABLERO; j++) {
            coordenada o = make_pair(i, j);
            for (int x = 0; x < ANCHO_TABLERO; x++) {
                for (int y = 0; y < ANCHO_TABLERO; y++) {
                    coordenada d = setCoord(x,y);
                    if(color(p.first, o) == p.second && esJugadaLegal(p, o, d)){
                        movibles.push_back(o);
                        movibles.push_back(d);
                    }
                }
            }
        }
    }
    return movibles;
}

posicion SecuenciaForzada(posicion p, secuencia s){
    vector<posicion> seq((s.size()*2)+1);
    seq[0] = p;
    for(int i = 1; i<seq.size(); i++){
        if(i % 2 == 1 ) { //es movimiento sin limites
            seq[i] = PosicionResultanteUnaJugada(seq[i-1], s[(i)/2].first, s[(i)/2].second );
        }else { //forzado
            vector <coordenada> movibles = ObtenerUnicasCoordenadasForzada(seq[i-1]);

            seq[i] = PosicionResultanteUnaJugada(seq[i-1], movibles[0], movibles[1]);
        }
    }
    return seq[seq.size() -1];
}

/// ejercicio 9

typedef pair < posicion, int > nodo;
typedef pair < coordenada , coordenada > parCoordenadas;

vector <parCoordenadas> ObtenerCoorMovimientoValidoJug(posicion p){
    vector <parCoordenadas> par;

    for(int i = 0; i<ANCHO_TABLERO;i++){
        for(int j = 0; j < ANCHO_TABLERO; j++) {
            coordenada o = make_pair(i, j);
            for (int x = 0; x < ANCHO_TABLERO; x++) {
                for (int y = 0; y < ANCHO_TABLERO; y++) {
                    coordenada d = setCoord(x,y);
                    if(color(p.first, o) == p.second && esJugadaLegal(p, o, d)){
                        par.push_back(make_pair(o, d));
                    }
                }
            }
        }
    }
    return par;
}


int jaqueEnKs(posicion p){

    vector<nodo> columna0;
    columna0.push_back(make_pair( p, 0));

    //primera serie de nodos
    vector<nodo> columna1;
    vector< parCoordenadas> par1 = ObtenerCoorMovimientoValidoJug(p);
    for(int i = 0; i<par1.size(); i++){
        posicion pAux1 = PosicionResultanteUnaJugada(p, par1[i].first, par1[i].second);
        if(!esJaqueMate(pAux1)){
            columna1.push_back(make_pair(pAux1, 0));
        }else return 1;
    }

    //eliminar nodos que no sirven, los negros que no tengan un unico movimiento claro
    //los "sobrevivientes" se convierten ahora al unico movimiento posible
    int i = 0;
    while(i<columna1.size()){
        vector<coordenada> movibles = ObtenerUnicasCoordenadasForzada(columna1[i].first);
        if(movibles.size() > 2 || movibles.size() == 0){
            columna1.erase(columna1.begin() + i);
        }else if (movibles.size() == 2){
            columna1[i].first = PosicionResultanteUnaJugada(columna1[i].first, movibles[0], movibles[1]);
            i++;
        }
    }

     //segunda tanda, columna 2
    vector<nodo> columna2;
    for(int j=0; j<columna1.size();j++){
        vector< parCoordenadas> par1 = ObtenerCoorMovimientoValidoJug(columna1[j].first);
        for(int i = 0; i<par1.size(); i++){
            posicion pAux1 = PosicionResultanteUnaJugada(columna1[j].first, par1[i].first, par1[i].second);
            if(!esJaqueMate(pAux1)){
                columna2.push_back(make_pair(pAux1, 1));
            }else return 2;
        }
    }

    //eliminar nodos que no sirven, los negros que no tengan un unico movimiento claro
    //los "sobrevivientes" se convierten ahora al unico movimiento posible
    i = 0;
    while(i<columna2.size()){
        vector<coordenada> movibles = ObtenerUnicasCoordenadasForzada(columna2[i].first);
        if(movibles.size() > 2 || movibles.size() == 0){
            columna2.erase(columna2.begin() + i);
        }else if (movibles.size() == 2){
            columna2[i].first = PosicionResultanteUnaJugada(columna2[i].first, movibles[0], movibles[1]);
            i++;
        }
    }

//tercer conjunt
    for(int j=0; j<columna2.size();j++){
        vector< parCoordenadas> par1 = ObtenerCoorMovimientoValidoJug(columna2[j].first);
        for(int i = 0; i<par1.size(); i++){
            posicion pAux1 = PosicionResultanteUnaJugada(columna2[j].first, par1[i].first, par1[i].second);
            if(esJaqueMate(pAux1)){
                return 3;
            }
        }
    }

    return -1;
}
