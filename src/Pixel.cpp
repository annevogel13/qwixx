/**
 * @file Pixel.cpp
 * @author AnLoVi
 * @brief Implémentation de la classe Pixel
 * @version 1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "Pixel.h"


Pixel :: Pixel () : r(0), g(0), b(0) {}


Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb){
    //Nombre entre 0 et 255
    if(nr<0) nr=0;
    if(ng<0) ng=0;
    if(nb<0) nb=0;
    /* Anne : je pense qu'on peut mieux faire une assert(0<=nr<=255) @p1906860
    Loris : Je me disais que faire des "if" permettait de corriger une erreur au lieu d'arrêter le programme...
    Mais si vous préférez des asserts, pas de soucis !
    En revanche assert(0<=nr<=255), ça me parait pas top en informatique. Mieux vaut assert(0<=nr && nr<=255) je crois */
    if(nr>255) nr=255;
    if(ng>255) ng=255;
    if(nb>255) nb=255;
    
    r = nr;
    g = ng;
    b = nb;
}

unsigned char Pixel::getRouge() const{
    return r;
}

unsigned char Pixel::getVert() const{
    return g;
}


unsigned char Pixel::getBleu() const{
    return b;
}


void Pixel::setRouge(unsigned char nr){
    r = nr;
}


void Pixel::setVert(unsigned char ng){
    g = ng;
}


void Pixel::setBleu(unsigned char nb){
    b = nb;
}