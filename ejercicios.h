#ifndef EJERCICIOS_H
#define EJERCICIOS_H

#include "definiciones.h"

bool posicionValida ( pair < tablero, int > const &p );
bool posicionInicial ( posicion const &p );
vector < coordenada > casillasAtacadas ( posicion const &p, int j );
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d );
void ordenarTablero ( posicion &p );
bool finDeLaPartida ( posicion const &p, int &j );
bool hayJaqueDescubierto ( posicion const &p );
void ejecutarSecuenciaForzada ( posicion &p, secuencia s );
int seVieneElJaqueEn ( posicion const & p );

//ejercicio 3

#define jugador int

bool enRango (int x, int m1, int m2);
bool coordenadaEnRango(coordenada c);
int abs(int n);
int apariciones(vector<coordenada> v, coordenada c );
int color(tablero t, coordenada c);
bool casillaVacia(tablero t, coordenada c);
int pieza (tablero t, coordenada c);
bool movimientoAlfilValido (tablero t,coordenada o, coordenada d);
bool mueveEnHorizontal (coordenada o, coordenada d) ;
bool mueveEnDiagonal (coordenada o, coordenada d);
bool mueveEnVertical (coordenada o, coordenada d) ;
bool movimientoReyValido (coordenada o, coordenada d);
bool movimientoPeonValido (int color, coordenada o, coordenada d);
bool capturaPeonValida ( tablero t, coordenada o, coordenada d) ;
bool movimientoTorreValido (tablero t, coordenada o, coordenada d);
bool movimientoPiezaValido (tablero t, coordenada o, coordenada d);
bool casillaAtacada (tablero t, coordenada o, coordenada d) ;
bool sonCasillasAtacadas (tablero t, jugador j, vector<coordenada> atacadas);

//fin ejercicio 3
#endif //
