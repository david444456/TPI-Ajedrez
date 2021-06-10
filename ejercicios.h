#ifndef EJERCICIOS_H
#define EJERCICIOS_H

#include "definiciones.h"

#define jugador int

bool posicionValida ( pair < tablero, int > const &p );
bool posicionInicial ( posicion const &p );
vector < coordenada > casillasAtacadas ( posicion const &p, int j );
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d );
void ordenarTablero ( posicion &p );
bool piezasEnCoordenadas(tablero t);
bool cantidadDePiezasAlInicio(tablero t);
bool finDeLaPartida ( posicion const &p, int &j );
bool hayJaqueDescubierto ( posicion const &p );
void ejecutarSecuenciaForzada ( posicion &p, secuencia s );
int seVieneElJaqueEn ( posicion const & p );
void ObtenerTableroOrdenado(tablero& t);

bool sonCasillasAtacadas (tablero t, jugador j, vector<coordenada> atacadas);
int apariciones(vector<coordenada> v, coordenada c );
bool casillaAtacada (tablero t, coordenada o, coordenada d);

#endif //
