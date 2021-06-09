#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    bool resp = false;
    resp = p.second == 1 || p.second == 2;
    resp = esTableroValido(p.first);
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
    for(int i = 0; i<p.first.size(); i++){
        for(int j = 0; j<p.first[i].size(); j++){
            coordenada c = setCoord(i,j);
            cA.push_back(c);
            if( !sonCasillasAtacadas(p.first,p.second,cA) ){
                cA.pop_back();
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
