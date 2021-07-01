//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

bool esJugadaLegal(posicion p, coordenada o, coordenada d);

bool cantidadDePiezasAlInicio(tablero t);

bool piezasEnCoordenadas(tablero t);

//3
bool esCapturaValida(posicion p, coordenada o, coordenada d);
int contrincante(int j);
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

vector<coordenada> obtenerCasillasAtacadas(tablero t,int j);

//4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d );
bool piezaCorrectaEnDestino(posicion p, posicion q, coordenada o, coordenada d);
bool esCapturaValida(posicion p, coordenada o,coordenada d);
bool esMovimientoValido(posicion p, coordenada o, coordenada d);
bool pertenece(vector<coordenada>c,coordenada d);
bool posicionesIgualesExceptoEn (posicion p, posicion q,vector<coordenada> C);
bool posicionSiguiente (posicion p, posicion q, coordenada o, coordenada d);

//5
void ObtenerTableroOrdenado(tablero& t);

//6
bool esTableroValido(tablero t);
bool esJaqueMate(posicion p);
bool jugadorEnJaque (posicion p, int j);
bool esEmpate (posicion p);
bool soloHayReyes (tablero t);
bool existeMovimientoParaSalirDelJaque(posicion p);
bool noHayMovimientosLegales (posicion p);

//7

bool alMoverQuedaEnJaque(posicion p);

//8
posicion SecuenciaForzada(posicion p, secuencia s);

//9
int jaqueEnKs(posicion p);

#endif //AJEDREZLITE_AUXILIARES_H
