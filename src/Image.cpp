/**
 * @file Image.cpp
 * @author AnLoVi
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

Image::Image(){
    dimx = 0;
    dimy = 0;
    tab = NULL;
}


Image::Image(const int &dimensionX, const int &dimensionY){
    assert(dimensionX >= 0);
    assert(dimensionY >= 0);
    dimx = dimensionX;
    dimy = dimensionY;
    if(dimensionX==0 && dimensionY==0)
        tab = NULL;
    else
        tab = new Pixel[dimensionX*dimensionY];

    //SDL :
    
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

Image::~Image(){
    dimx = 0;
    dimy = 0;
    if(tab!=NULL){
        delete [] tab;
        tab = NULL;
    }
}

Pixel& Image::getPix (const unsigned int &x, const unsigned int &y) const{
    assert(x<dimx);
    assert(y<dimy);
    return tab[y*dimx+x];
}

void Image::setPix (const unsigned int &x,const unsigned int &y, const Pixel &couleur){
    tab[y*dimx+x] = couleur;
}


void Image::dessinerRectangle (const unsigned int &Xmin,const unsigned int &Ymin, const unsigned int &Xmax,const unsigned int &Ymax, const Pixel &couleur){
    unsigned int i,j;
    assert(Xmax<dimx); //Pas <= car le pixel 0 compte !! 
    assert(Ymax<dimy);
    assert(Xmin<Xmax);
    assert(Ymin<Ymax);    

    for(i=Xmin;i<=Xmax;i++){
        for(j=Ymin;j<=Ymax;j++){
            setPix(i,j,couleur);
        }
    }
}


void Image::effacer (const Pixel &couleur){
    dessinerRectangle(0,0,dimx-1,dimy-1,couleur);
}


void Image::testRegression (){
    //1-- Test constructeur d'une image
    Image im;
    assert(im.dimx==0);
    assert(im.dimy==0);
    assert(tab==NULL);

    //1_BIS-- Test image à 0
    Image im3(0,0);
    assert(im3.dimx==0);
    assert(im3.dimy==0);
    assert(im3.tab==NULL);

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

void Image::sauver(const string & filename) const {
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    
    for(unsigned int y=0; y<dimy; y++){
        for(unsigned int x=0; x<dimx; x++) {            
            Pixel& pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " "; //Ajout GETCOULEUR()
        }
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

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
            getPix(x,y).setRouge((unsigned char)r);
            getPix(x,y).setVert((unsigned char)g);
            getPix(x,y).setBleu((unsigned char)b);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}



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


//---------------------------------------------//
//--------------POUR SDL-----------------------//
//---------------------------------------------//
void Image::afficher(){
    sauver("./data/tmp.ppm");
    afficherInit();
    loadFromFile("./data/tmp.ppm",renderer);
    //cout<<"w= "<<surface->w<<" et h = "<<surface->h<<endl;
    afficherBoucle();
    

    //DELETE IMAGE AFFICHER_INIT + DELETE tmp.ppm
    afficherDetruit();
    remove("data/tmp.ppm");
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

void Image::afficherInit()
{
    window = nullptr;
    renderer = nullptr;  
    //font = nullptr;
    //Image * image = new Image;
    //Image * font_im = new Image;

    
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }
    /*
    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;SDL_Quit();exit(1);
    }*/

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }
	int dimx, dimy;
	dimx = 200;
	dimy = 200;

    // Creation de la fenetre
    window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    loadFromFile("data/image1.ppm",renderer);

    /* FONT est inutile pour notre module
    // FONTS
    font = TTF_OpenFont("DejaVuSansCondensed.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
	}

    SDL_Color font_color;
	font_color.r = 50;
    font_color.g = 50;
    font_color.b = 255;
    
	font_im->setSurface(TTF_RenderText_Solid(font,"Pacman",font_color));
	font_im->loadFromCurrentSurface(renderer);*/
    
}

void Image::afficherBoucle () {
    SDL_Event events;
	bool quit = false;
    int taille_w = 100;
    int taille_h = 100;

    //Uint32 t = SDL_GetTicks(), nt;

	// tant que ce n'est pas la fin ...
	while (!quit) {

		// tant qu'il y a des evenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) 
            {
				switch (events.key.keysym.scancode) 
                {
                    case SDL_SCANCODE_ESCAPE:
                        quit=true;
                        break;
                    case SDL_SCANCODE_T:
                        // Zoom avant
                        //cout<<"Zoom avant"<<endl;
                        taille_w +=20;
                        taille_h +=20;
                        break;
                    case SDL_SCANCODE_G:
                        // Zoom arrière
                        //cout<<"Zoom arrière"<<endl;
                        if(taille_w > 21 || taille_h > 21){   // taille est de tye int, donc le plus petit image qu' on peut affiche est 1 21-20 = 1 
                            taille_w -=20;
                            taille_h -=20;
                        }else taille_w = taille_h = 21 ;  

                       
                        
                        break;
                    default: break;
				}
			}
		}

		// on affiche l'image sur le buffer caché
		//sdlAff();

        //Les 7 lignes suivantes sont égales à la fonction sdlAff() de l'exemple.
        //Cela évite ici de recréer une fonction...
        //Remplir l'écran de blanc
        SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
        SDL_RenderClear(renderer);

	    // Afficher le sprite de Pacman
        
        int w;
        int h;
        SDL_GetWindowSize(window,&w,&h); //Permet de connaitre les dimensions de la fenêtre

	    draw(renderer,w/2 - taille_w/2,h/2-taille_h/2, taille_w, taille_h); //Positionne l'image au CENTRE !

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}

void Image::afficherDetruit(){
    //TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
