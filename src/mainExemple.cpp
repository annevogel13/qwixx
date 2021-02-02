#include <iostream>
#include "Image.h"
 
 using namespace std;

int main() {
    Pixel bleu (170, 207, 224);
    Pixel rouge (241, 47, 4);
    Pixel vert (23, 232, 37);
    Pixel noir (0,0,0);

    
    /*
    cout<<"Test"<<endl;
    Image img(5,5);
    img.effacer(rouge);
    //img.afficherConsole();
    img.sauver("./data/img.ppm");
    img.ouvrir("./data/img.ppm");
    cout<<"Nouvelle image"<<endl;
    img.afficherConsole();
    cout<<"Taille image = "<<(int) sizeof(img);
    */

    
    Image image1 (64,48);    
    image1.effacer(bleu);
    
    image1.dessinerRectangle(32, 24, 46, 35, rouge);
    image1.setPix(6,10,noir);
    image1.setPix(41,30,vert);
    image1.sauver("./data/image1.ppm");
 
    Image image2;
    image2.ouvrir("./data/image1.ppm");
    image2.dessinerRectangle(2, 2, 7, 13, vert);
    image2.dessinerRectangle(38, 18, 43, 46, noir);
    image2.sauver("./data/image2.ppm");
    
    std::cout<<std::endl<<"FIN";
    return 0;
}