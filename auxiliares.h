//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H
#define jugador int
#define DIM 8

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

//3
bool esCapturaValida(posicion p, coordenada o, coordenada d);
int contrincante(int j);

//6
bool esTableroValido(tablero t);
bool esJaqueMate(posicion p);
bool jugadorEnJaque (posicion p, jugador j);
bool esEmpate (posicion p);
bool soloHayReyes (tablero t);
bool existeMovimientoParaSalirDelJaque(posicion p);
bool noHayMovimientosLegales (posicion p);



#endif //AJEDREZLITE_AUXILIARES_H
