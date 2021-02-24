#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @brief Classe gérant l'image à créer/afficher
 * 
 */
class Image{
    private:
        Pixel * tab;
        unsigned int dimx,dimy;

        //SDL
        SDL_Window * window;
        SDL_Surface * surface;
        SDL_Texture * texture;
        SDL_Renderer * renderer;
        //TTF_Font *font;
       bool has_changed;
    
    public:
        /**
         * @brief Constructeur de la classe Image. Initialisation de dimx,dimy à 0 et du pointeur tab à NULL.
         * @details N'alloue pas de pixels.
         * 
         */
        Image ();
        
        /**
         * @brief Constructeur de la classe Image avec données passées en paramètre
         * 
         * @param dimensionX 
         * @param dimensionY 
         */
        Image (const int &dimensionX, const int &dimensionY);

        /**
         * @brief Destructeur de la classe Image.
         * 
         */
        ~Image ();

        /**
         * @brief Obtention du pixel de coordonnée (x,y)
         * 
         * @param x 
         * @param y 
         * @return Pixel& 
         */        
        Pixel& getPix (const unsigned int &x, const unsigned int &y) const;

        /**
         * @brief Initialisation du pixel (x,y) à la couleur passée en paramètre.
         * 
         * @param x 
         * @param y 
         * @param couleur 
         */
        void setPix (const unsigned int &x,const unsigned int &y, const Pixel &couleur);

        /**
         * @brief Dessine un rectangle de (Xmin,Ymin) à (Xmax,Ymax) avec la couleur passée en paramètre.
         * 
         * @param Xmin 
         * @param Ymin 
         * @param Xmax 
         * @param Ymax 
         * @param couleur 
         */
        void dessinerRectangle (const unsigned int &Xmin,const unsigned int &Ymin, const unsigned int &Xmax, const unsigned int &Ymax,const Pixel &couleur);

        /**
         * @brief Efface toute l'image en remplissant avec la couleur passée en paramètre.
         * 
         * @param couleur 
         */
        void effacer (const Pixel &couleur);

        /**
         * @brief Test des différentes fonctions de la classe image. (Test constucteur par défaut, constructeur par copie, test des asseceurs/mutateurs, test de dessinerRectangle(), test de effacer())
         * 
         */
        void testRegression ();

        /**
         * @brief Sauvegarde de l'image dans un fichier au format filename.ppm
         * 
         * @param filename 
         */
        void sauver(const std::string & filename) const;

        /**
         * @brief Ouverture de l'image filename.ppm
         * 
         * @param filename 
         */
        void ouvrir(const std::string & filename);

        /**
         * @brief Affiche les pixels de l'image dans la console. 
         * 
         */
        void afficherConsole();

        //----------------------------
        //-------------SDL------------
        //----------------------------

        
        /**
         * @brief Affiche l'image dans une fenêtre SDL2 
         * 
         */
        void afficher ();

        /**
         * @brief Charge un fichier image dans une surface
         * 
         * @param filename Chemin de l'image
         * @param renderer Renderer SDL
         */
        void loadFromFile (const char* filename, SDL_Renderer * renderer);
        
        /**
         * @brief Initialise la fenêtre SDL
         * 
         */
        void afficherInit ();

        /**
         * @brief Détruit la fenêtre SDL
         * 
         */
        void afficherDetruit ();       

        /**
         * @brief Boucle gérant les évenements clavier dans SDL
         * 
         */
        void afficherBoucle ();

        /**
         * @brief Dessine le renderer à l'écran
         * 
         * @param renderer 
         * @param x Position en x (coin supérieur gauche)
         * @param y Position en y (coin supérieur gauche)
         * @param w Largeur du dessin
         * @param h Hauteyr du dessin
         */
        void draw (SDL_Renderer * renderer, int x, int y, int w, int h);

};


#endif