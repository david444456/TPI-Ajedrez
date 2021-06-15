#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(ordenarTableroTEST, ordenarPosicionInicial){
    tablero t = {
    {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
    {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
    {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
    {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
    {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };
    tablero t_ord = {
            {cALFIL_N,  cVACIA,     cALFIL_N,   cVACIA,     cTORRE_N,   cTORRE_N,   cVACIA,     cREY_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cALFIL_B,  cVACIA,     cALFIL_B,   cVACIA,     cTORRE_B,   cTORRE_B,   cVACIA,     cREY_B},
    };
    posicion p = make_pair(t,BLANCO);
    ordenarTablero(p);
    EXPECT_EQ(tableroActual(p), t_ord);
}
TEST(ordenarTableroTEST, yaEstabaOrdenado){
    tablero t = {
            {cTORRE_N, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    tablero t_ord = {
            {cTORRE_N, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA, cVACIA},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);
    ordenarTablero(p);
    EXPECT_EQ(tableroActual(p), t_ord);
}

TEST(ordenarTableroTEST, PrimerasYUltimasFilasLlenas){
    tablero t = {
            {cTORRE_N,  cALFIL_N,     cREY_N,   cALFIL_N,    cTORRE_N ,    cTORRE_N ,   cTORRE_N,    cTORRE_N },
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cPEON_B,     cALFIL_B,   cPEON_B,     cREY_B,     cALFIL_B,   cPEON_B,     cTORRE_B},
    };
    tablero t_ord = {
            {cALFIL_N,  cALFIL_N,     cTORRE_N,   cTORRE_N,     cTORRE_N,   cTORRE_N,   cTORRE_N,     cREY_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cPEON_B,  cPEON_B,     cPEON_B,  cALFIL_B ,     cALFIL_B,   cTORRE_B,   cTORRE_B,     cREY_B},
    };
    posicion p = make_pair(t,BLANCO);
    ordenarTablero(p);
    EXPECT_EQ(tableroActual(p), t_ord);
}

TEST(ordenarTableroTEST, PrimerasYUltimasFilasLlenasColoresMixtos){
    tablero t = {
            {cTORRE_N,  cALFIL_N,     cREY_N,   cALFIL_B,    cTORRE_N ,    cTORRE_N ,   cTORRE_N,    cTORRE_N },
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cPEON_B,     cALFIL_N,   cPEON_B,     cREY_B,     cALFIL_B,   cPEON_B,     cTORRE_B},
    };
    tablero t_ord = {
            {cALFIL_B,  cALFIL_N,     cTORRE_N,   cTORRE_N,     cTORRE_N,   cTORRE_N,   cTORRE_N,     cREY_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cPEON_B,  cPEON_B,     cPEON_B,  cALFIL_B,    cALFIL_N,   cTORRE_B,   cTORRE_B,     cREY_B},
    };
    posicion p = make_pair(t,BLANCO);
    ordenarTablero(p);
    EXPECT_EQ(tableroActual(p), t_ord);
}

TEST(ordenarTableroTEST, TodasLasFilasConPiezasColoresMixtos){
    tablero t = {
            {cTORRE_N,  cALFIL_N,     cREY_N,   cALFIL_B,    cTORRE_N ,    cTORRE_N ,   cTORRE_N,    cTORRE_N },
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cPEON_N,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cPEON_N,     cVACIA,     cVACIA,     cREY_B,     cVACIA,     cPEON_N,     cVACIA},
            {cVACIA,    cALFIL_B,     cVACIA,     cVACIA,     cVACIA,     cPEON_N,     cVACIA,     cVACIA},
            {cTORRE_B,  cPEON_B,     cALFIL_N,   cREY_B,     cREY_N,     cALFIL_B,   cREY_B,     cTORRE_B},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cPEON_B,     cALFIL_N,   cPEON_B,     cREY_B,     cALFIL_B,   cPEON_B,     cTORRE_B},
    };
    tablero t_ord = {
            {cALFIL_B,  cALFIL_N,     cTORRE_N,   cTORRE_N,     cTORRE_N,   cTORRE_N,   cTORRE_N,     cREY_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cPEON_N,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cPEON_N,     cVACIA,     cVACIA,     cPEON_N,     cVACIA,     cREY_B,     cVACIA},
            {cVACIA,    cPEON_N,     cVACIA,     cVACIA,     cVACIA,     cALFIL_B,     cVACIA,     cVACIA},
            {cPEON_B ,  cALFIL_B,     cALFIL_N,   cTORRE_B,    cTORRE_B ,   cREY_B,  cREY_B,     cREY_N},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cPEON_B,  cPEON_B,     cPEON_B,  cALFIL_B,    cALFIL_N,   cTORRE_B,   cTORRE_B,     cREY_B},
    };
    posicion p = make_pair(t,BLANCO);
    ordenarTablero(p);
    EXPECT_EQ(tableroActual(p), t_ord);
}

