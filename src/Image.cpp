/**
 * @file Image.cpp
 * @author Loris Mercier
 * @brief Implémentation de la classe Image
 * @version 1
 * @date 2021-01-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cassert>
#include <fstream>
#include "Image.h"

using namespace std;


/**
 * @brief Constructeur de la classe Image. Initialisation de dimx,dimy à 0 et du pointeur tab à NULL.
 * 
 * 
 */
Image::Image(){
    dimx = 0;
    dimy = 0;
    tab = NULL;
}

/**
 * @brief Constructeur de la classe Image avec données passées en paramètre
 * 
 * @param dimensionX 
 * @param dimensionY 
 */
Image::Image(const int &dimensionX, const int &dimensionY){
    assert(dimensionX >= 0);
    assert(dimensionY >= 0);
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimensionX*dimensionY];
}
// ce doit pas etre une image noire?  je pense que on doit initialiser le tab Pixel avec des pixels noires 
/* 
    Pixel P(0,0,0); 
    for(int i = 0; i <dimx ; i++){
        for(int j=0; j<dimy ; j++){
            setPix(i,j,P)
        }
    }
*/ 

/**
 * @brief Destructeur de la classe Image.
 * 
 */
Image::~Image(){
    dimx = 0;
    dimy = 0;
    if(tab!=NULL){
        delete [] tab;
        tab = NULL;
    }
}

/**
 * @brief Obtention du pixel de coordonnée (x,y)
 * 
 * @param x 
 * @param y 
 * @return Pixel& 
 */
Pixel& Image::getPix (const unsigned int &x, const unsigned int &y) const{
    assert(x<dimx);
    assert(y<dimy);
    return tab[y*dimx+x];
}

/**
 * @brief Initialisation du pixel (x,y) à la couleur passée en paramètre.
 * 
 * @param x 
 * @param y 
 * @param couleur 
 */
void Image::setPix (const unsigned int &x,const unsigned int &y, const Pixel &couleur){
    tab[y*dimx+x] = couleur;
}


/**
 * @brief Dessine un rectangle de (Xmin,Ymin) à (Xmax,Ymax) avec la couleur passée en paramètre.
 * 
 * @param Xmin 
 * @param Ymin 
 * @param Xmax 
 * @param Ymax 
 * @param couleur 
 */
void Image::dessinerRectangle (const unsigned int &Xmin,const unsigned int &Ymin, const unsigned int &Xmax,const unsigned int &Ymax, const Pixel &couleur){
    unsigned int i,j;
    assert(Xmax<dimx); //Pas <= car le pixel 0 compte !! Tu est sure? --> Xmax <=dimx pour la fonction effacer?
    assert(Ymax<dimy);
    assert(Xmin<Xmax);
    assert(Ymin<Ymax);    

    for(i=Xmin;i<=Xmax;i++){
        for(j=Ymin;j<=Ymax;j++){
            setPix(i,j,couleur);
        }
    }
}


/**
 * @brief Efface toute l'image en remplissant avec la couleur passée en paramètre.
 * 
 * @param couleur 
 */
void Image::effacer (const Pixel &couleur){
    dessinerRectangle(0,0,dimx-1,dimy-1,couleur);  // pourquoi dimx-1? 
}


/**
 * @brief Test des différentes fonctions de la classe image. (Test constucteur par défaut, constructeur par copie, test des asseceurs/mutateurs, test de dessinerRectangle(), test de effacer())
 * 
 */
void Image::testRegression (){
    //1-- Test constructeur d'une image
    Image im;
    assert(im.dimx==0);
    assert(im.dimy==0);
    assert(tab==NULL);

    //2-- Test constructeur avec param
    Image im2(20,30);
    assert(im2.dimx==20);
    assert(im2.dimy==30);

    //test image noire
    for(int i=0;i<20*30;i++){
        assert(im2.tab[i].getRouge()==0);
        assert(im2.tab[i].getVert()==0);
        assert(im2.tab[i].getBleu()==0);
    }

    //4-- Test accesseur/mutateur
    Pixel p(155,156,157);

    im2.setPix(10,20,p);
    assert(im2.tab[20*20+10].getRouge()==155);
    assert(im2.tab[20*20+10].getVert()==156);
    assert(im2.tab[20*20+10].getBleu()==157);

    p = im2.getPix(10,20);
    assert(p.getRouge()==155);
    assert(p.getVert()==156);
    assert(p.getBleu()==157);

    //5-- Test dessin rectangle (qui recouvre le pixel [10,20])
    im2.dessinerRectangle(0,0,10,10,p);
    //test de la couleur
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            assert(im2.getPix(i,j).getRouge()==155);
            assert(im2.getPix(i,j).getVert()==156);
            assert(im2.getPix(i,j).getBleu()==157);
        }
    }
    //test autre pixel toujours noir
    for(unsigned int i=11;i<im2.dimx;i++){
        for(unsigned int j=11;j<im2.dimy;j++){
            assert(im2.getPix(i,j).getRouge()==0);
            assert(im2.getPix(i,j).getVert()==0);
            assert(im2.getPix(i,j).getBleu()==0);
        }
    }

    //6-- Test effacer
    p.setRouge(201);
    p.setVert(202);
    p.setBleu(203);
    im2.effacer(p);

    //test image rempli avec p(201,202,203)
    for(unsigned int i=0;i<im2.dimx;i++){
        for(unsigned int j=0;j<im2.dimy;j++){
            assert(im2.getPix(i,j).getRouge()==201);
            assert(im2.getPix(i,j).getVert()==202);
            assert(im2.getPix(i,j).getBleu()==203);
        }
    }
}

/**
 * @brief Sauvegarde de l'image dans un fichier au format filename.ppm
 * 
 * @param filename 
 */
void Image::sauver(const string & filename) const { //Enlevement de const
    //cout<<"DEBUT"<<"  "<<filename<<endl;
    //ofstream fichier(filename.c_str());
    ofstream fichier(filename.c_str());
    //cout<<"avant test";
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    //cout<<"avant boucle";
    for(unsigned int y=0; y<dimy; y++){
        for(unsigned int x=0; x<dimx; x++) {            
            Pixel& pix = getPix(x,y);
            //cout<<" x= "<<x<<" et y= "<<y;
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " "; //Ajout GETCOULEUR()
        }
        //cout<<endl; //A enlever
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

/**
 * @brief Ouverture de l'image filename.ppm
 * 
 * @param filename 
 */
void Image::ouvrir(const string & filename){
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	unsigned int r,g,b;
	string mot;
	dimx = dimy = 0;

	fichier >> mot >> dimx >> dimy >> mot;

	assert(dimx > 0 && dimy > 0);

	if (tab != NULL) delete [] tab;
    
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; y++){
        for(unsigned int x=0; x<dimx; x++) {
            fichier >> r >> g >> b;//rgb et non rbg
            //cout<<"R brut : "<<r<<" R en int : "<<(unsigned char) r<<endl;
            getPix(x,y).setRouge((unsigned char)r);
            getPix(x,y).setVert((unsigned char)g);
            getPix(x,y).setBleu((unsigned char)b);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}



/**
 * @brief Affiche les pixels de l'image dans la console. 
 * 
 */
void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; y++) {
        for(unsigned int x=0; x<dimx; x++){
            Pixel& pix = getPix(x,y); 
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}


/*
//Question :
- Dans doxygen, faut-il faire un @return void ?
        - Anne : aucune idee 
- Dans les ppm, faut il des chiffres où des caractères ?
        - Anne: chiffres car --> " It stores each pixel with a number from 0 to 65536, 
                which specifies the color of the pixel
- Makefile qui refait toujours les .o, est-ce normal ?
        - Anne: oui je pense que c' est normal. Quand chaque fois que on change quelque chose
                le code change, et 'ca affecte le .o 
*/
