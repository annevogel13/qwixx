#ifndef _PIXEL
#define _PIXEL

/**
 * @brief Classe formant un Pixel (r,g,b)
 * 
 */
class Pixel{
    private:
        unsigned char r,g,b;
    public:
        /**
         * @brief Constructeur de la classe Pixel. Mise à zero des trois données r,g,b.
         * 
         * @return Pixel 
         */
        Pixel();

        /**
         * @brief Constructeur de la classe Pixel. Initialisation de r,g,b avec les valeurs en paramètre.
         * 
         * @param nr 
         * @param ng 
         * @param nb 
         */
        Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

        /**
         * @brief Accesseur vers la donnée r
         * 
         * @return unsigned char 
         */
        unsigned char getRouge () const;

        /**
         * @brief Accesseur vers la donnée g
         * 
         * @return unsigned char 
         */
        unsigned char getVert () const;

        /**
         * @brief Accesseur vers la donnée b
         * 
         * @return unsigned char 
         */
        unsigned char getBleu () const;

        /**
         * @brief Mutateur de la donnée r
         * 
         * @param nr 
         */
        void setRouge ( unsigned char nr);
        
        /**
         * @brief Mutateur de la donnée g
         * 
         * @param ng 
         */
        void setVert (unsigned char nv);
        
        /**
         * @brief Mutateur de la donnée b
         * 
         * @param nb 
         */
        void setBleu (unsigned char nb);
};
#endif