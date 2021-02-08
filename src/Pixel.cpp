/**
 * @file Pixel.cpp
 * @author Loris Mercier
 * @brief Implémentation de la classe Pixel
 * @version 1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "Pixel.h"

/**
 * @brief Constructeur de la classe Pixel. Mise à zero des trois données r,g,b.
 * 
 * @return Pixel 
 */
Pixel :: Pixel () : r(0), g(0), b(0) {}
// @Loris je ne comprends pas comment tu fais?? car ca doit pas etre comme Pixel(){ r(0) ... }
//          Loris : En C++, on a le droit d'utiliser cette syntaxe, c'est plus performant. Je ne peux pas te dire
//                  pourquoi, mais c'est mieux de faire comme ça.


/**
 * @brief Constructeur de la classe Pixel. Initialisation de r,g,b avec les valeurs en paramètre.
 * 
 * @param nr 
 * @param ng 
 * @param nb 
 */
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

/**
 * @brief Accesseur vers la donnée r
 * 
 * @return unsigned char 
 */
unsigned char Pixel::getRouge(){
    return r;
}

/**
 * @brief Accesseur vers la donnée g
 * 
 * @return unsigned char 
 */
unsigned char Pixel::getVert(){
    return g;
}


/**
 * @brief Accesseur vers la donnée b
 * 
 * @return unsigned char 
 */
unsigned char Pixel::getBleu(){
    return b;
}


/**
 * @brief Mutateur de la donnée r
 * 
 * @param nr 
 */
void Pixel::setRouge(unsigned char nr){
    r = nr;
}


/**
 * @brief Mutateur de la donnée g
 * 
 * @param ng 
 */
void Pixel::setVert(unsigned char ng){
    g = ng;
}


/**
 * @brief Mutateur de la donnée b
 * 
 * @param nb 
 */
void Pixel::setBleu(unsigned char nb){
    b = nb;
}