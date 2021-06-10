#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    bool resp = false;
    resp = p.second == 1 || p.second == 2;
    resp = resp && esTableroValido(p.first);
    // completar codigo
    return resp;
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    bool resp = false;
    resp = piezasEnCoordenadas(p.first) && p.second == BLANCO && cantidadDePiezasAlInicio(p.first);
    return resp;
}

// EJERCICIO 3
vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    vector <coordenada> cA;
    for(int x = 0; x<p.first.size(); x++){
        for(int y = 0; y<p.first[x].size(); y++){
            coordenada c = setCoord(x,y);
            for(int a =0; a<p.first.size();a++){
                for(int b =0; b<p.first[a].size();b++){
                    coordenada o = setCoord(a,b);
                    if(apariciones(cA,c)==0 && casillaAtacada(p.first,o,c)
                        && p.first[o.first][o.second].second == j){
                        cA.push_back(c);
                    }
                }
            }
        }
    }
    return cA;
}

// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    bool resp = false;
   // resp = posicionSiguiente(p1,p2,0,d);
    // completar codigo
    return resp;
}

// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    ObtenerTableroOrdenado(p.first);

    return;
}

// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool resp = false;
    // completar codigo
    return resp;
}

// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    bool resp = false;
    // completar codigo
    return resp;
}

// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    // completar codigo
    return;
}

// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int resp = -1;
    // completar codigo
    return resp;
}
