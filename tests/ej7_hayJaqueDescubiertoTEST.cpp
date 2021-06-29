#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

/*TEST(hayJaqueDescubiertoTEST, ) {
	tablero t = {
            {cVACIA, cREY_N, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
	posicion p = make_pair(t, BLANCO);

	EXPECT_TRUE(hayJaqueDescubierto(p));
}*/
TEST(hayJaqueDescubiertoTEST, noHayJaque) {
	tablero t = {	// Tablero Inicial
	    {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
	    {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
	    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
	    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
	    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
	    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
	    {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
	    {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };
	posicion p = make_pair(t, BLANCO);

	EXPECT_FALSE(hayJaqueDescubierto(p));
}

TEST(hayJaqueDescubiertoTEST, jaqueDescubierto) {
	tablero t = {	// Figura del ej15 del enunciado del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
	posicion p = make_pair(t, BLANCO);

	EXPECT_TRUE(hayJaqueDescubierto(p));
}

TEST(hayJaqueDescubiertoTEST, jaqueDescubiertoMovimientoPeon) {
    tablero t = {		// Figura 5 del enunciado del TPE
                             {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
                             {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
                             {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
                             {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cREY_N},
                             {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
                             {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
                             {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA},
                             {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cTORRE_B},
                             };


    posicion p = make_pair(t, BLANCO);

    EXPECT_TRUE(hayJaqueDescubierto(p));
}
TEST(hayJaqueDescubiertoTEST, jaqueDescubiertocomepeonnegro) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, BLANCO);

    EXPECT_TRUE(hayJaqueDescubierto(p));
}

TEST(hayJaqueDescubiertoTEST, hayJaquePeroNoDescubierto) {
    tablero t = {	// Cuarto tablero de la Figura 5 del enunciado del TPE, con colores opuestos.
            {cTORRE_N, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    EXPECT_FALSE(hayJaqueDescubierto(p));
}


TEST(hayJaqueDescubiertoTEST, hayJaquePeroNoEsMate) {
        tablero t = {
                {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
                {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cVACIA,     cPEON_N,    cPEON_N,    cPEON_N},
                {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
                {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cPEON_N,    cTORRE_B,   cVACIA,     cVACIA},
                {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
                {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
                {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
                {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cVACIA},
        };
        posicion p = make_pair(t, BLANCO);
    EXPECT_FALSE(hayJaqueDescubierto(p));
}