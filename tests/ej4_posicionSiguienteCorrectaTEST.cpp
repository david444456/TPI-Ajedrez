#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(posicionSiguienteCorrectaTEST, adelantoPeon){
    tablero t_p = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cPEON_B,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cVACIA,     cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    posicion p = make_pair(t_p,BLANCO);
    posicion q = make_pair(t_q,NEGRO);

    coordenada o = setCoord(6,2);
    coordenada d = setCoord(5,2);

    EXPECT_TRUE(posicionSiguienteCorrecta(p,q,o,d));
}

TEST(posicionSiguienteCorrectaTEST, peonHaceSaltoDelTigre){
    tablero t_p = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cPEON_B,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cVACIA,     cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    posicion p = make_pair(t_p,BLANCO);
    posicion q = make_pair(t_q,NEGRO);

    coordenada o = setCoord(6,2);
    coordenada d = setCoord(2,2);

    EXPECT_FALSE(posicionSiguienteCorrecta(p,q,o,d));
}


TEST(posicionSiguienteCorrectaTEST, comealfilB){
    tablero t_p = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cPEON_N,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cVACIA,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    tablero t_q = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cALFIL_B,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cPEON_B,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cVACIA,     cVACIA,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cVACIA,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    posicion p = make_pair(t_p,BLANCO);
    posicion q = make_pair(t_q,NEGRO);

    coordenada o = setCoord(7,2);
    coordenada d = setCoord(4,5);



    EXPECT_TRUE(posicionSiguienteCorrecta(p,q,o,d));
}

TEST(posicionSiguienteCorrectaTEST_Blufstein, peonSeCoronaComiendoUnaPieza){
    tablero t_1 = {
            {cVACIA,  cVACIA,     cVACIA,    cTORRE_N,   cVACIA,    cVACIA,   cVACIA,     cREY_N},
            {cVACIA,   cVACIA,    cPEON_B,   cVACIA,    cVACIA,    cVACIA,    cVACIA,     cVACIA},
            {cVACIA,    cVACIA,   cVACIA,    cVACIA,    cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,   cVACIA,    cVACIA,    cVACIA,     cVACIA,   cVACIA,     cTORRE_N},
            {cVACIA,    cVACIA,   cVACIA,    cVACIA,    cALFIL_B,   cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,   cVACIA,    cVACIA,    cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,   cVACIA,    cVACIA,    cVACIA,    cPEON_B,    cPEON_B,  cVACIA,     cVACIA},
            {cREY_B,  cVACIA,     cVACIA,   cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
    };
    tablero t_2 = {
            {cVACIA,  cVACIA,     cVACIA,   cTORRE_B,   cVACIA,     cVACIA,   cVACIA,     cREY_N},
            {cVACIA,   cVACIA,    cVACIA,   cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,    cVACIA,   cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,   cVACIA,   cVACIA,     cVACIA,     cVACIA,   cVACIA,     cTORRE_N},
            {cVACIA,    cVACIA,   cVACIA,   cVACIA,     cALFIL_B,   cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,   cVACIA,   cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,   cVACIA,    cVACIA,   cVACIA,     cPEON_B,    cPEON_B,  cVACIA,     cVACIA},
            {cREY_B,  cVACIA,     cVACIA,   cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
    };


    posicion p_1 = make_pair(t_1,BLANCO);
    posicion p_2 = make_pair(t_2,NEGRO);
    coordenada o = setCoord(1,2);
    coordenada d = setCoord(0,3);

    EXPECT_TRUE(posicionSiguienteCorrecta(p_1,p_2,o,d));
}

TEST(posicionSiguienteCorrectaTEST, peonNoCoronado){
    tablero t_p = {
            {cVACIA,    cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cPEON_N,    cVACIA,    cVACIA,      cPEON_N,    cPEON_N,    cPEON_B,    cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cTORRE_N,  cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cVACIA,     cVACIA,     cPEON_B,    cVACIA,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    tablero t_q = {
            {cVACIA,    cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cVACIA,   cPEON_B,     cVACIA},
            {cVACIA,    cPEON_N,    cVACIA,    cVACIA,      cPEON_N,    cPEON_N,    cVACIA,    cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cTORRE_N,  cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,   cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cVACIA,     cVACIA,     cPEON_B,    cVACIA,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };

    posicion p = make_pair(t_p,BLANCO);
    posicion q = make_pair(t_q,NEGRO);

    coordenada o = setCoord(1,6);
    coordenada d = setCoord(0,6);

    EXPECT_FALSE(posicionSiguienteCorrecta(p,q,o,d));
}