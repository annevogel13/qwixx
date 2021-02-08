#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <string>

class Image{
    private:
        Pixel * tab;
        unsigned int dimx,dimy;
    
    public:
        // Constructeur par défaut de la classe: initialise dimx et dimy à 0
        // ce constructeur n'alloue pas de pixel
        Image ();
        
        // Constructeur de la classe: initialise dimx et dimy (après vérification)
        // puis alloue le tableau de pixel dans le tas (image noire)
        Image (const int &dimensionX, const int &dimensionY);

        // Destructeur de la classe: déallocation de la mémoire du tableau de pixels
        // et mise à jour des champs dimx et dimy à 0
        ~Image ();

        // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
        // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
        Pixel& getPix (const unsigned int &x, const unsigned int &y) const;
        //Anne : pourquoi tu as mis Pixel& ?  @p1906860
        //Loris : Car il ne faut pas renvoyer "une copie" mais le PIXEL original. Donc, on utilise la référence Pixel&.
        //        J'avais fait la même erreur, mais Mr Pronost en a parlé sur discord.  

        // Mutateur : modifie le pixel de coordonnées (x,y)
        void setPix (const unsigned int &x,const unsigned int &y, const Pixel &couleur);

        // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
        void dessinerRectangle (const unsigned int &Xmin,const unsigned int &Ymin, const unsigned int &Xmax, const unsigned int &Ymax,const Pixel &couleur);

        // Efface l'image en la remplissant de la couleur en paramètre
        // (en appelant dessinerRectangle avec le bon rectangle)
        void effacer (const Pixel &couleur);

        // Effectue une série de tests vérifiant que le module fonctionne et
        // que les données membres de l'objet sont conformes
        void testRegression ();

        //Sauve une image dans un fichier
        void sauver(const std::string & filename) const;

        void ouvrir(const std::string & filename);

        void afficherConsole();

};


#endif