all: exemple

exemple: ./obj/mainExemple.o ./obj/Image.o ./obj/Pixel.o
			g++ -g ./obj/mainExemple.o ./obj/Image.o ./obj/Pixel.o -o ./bin/exemple -lSDL2 -lSDL2_ttf -lSDL2_image

affichage: ./obj/mainAffichage.o ./obj/Image.o ./obj/Pixel.o
			g++ -g ./obj/mainAffichage.o ./obj/Image.o ./obj/Pixel.o -o ./bin/affichage -lSDL2 -lSDL2_ttf -lSDL2_image

./obj/mainExemple.o: ./src/mainExemple.cpp ./src/Image.h ./src/Pixel.h
				g++ -g -Wall -c ./src/mainExemple.cpp -o ./obj/mainExemple.o 

./obj/Image.o: ./src/Image.h ./src/Image.cpp ./src/Pixel.h
				g++ -g -Wall -c ./src/Image.cpp -o ./obj/Image.o

./obj/Pixel.o: ./src/Pixel.h ./src/Pixel.cpp
				g++ -g -Wall -c ./src/Pixel.cpp -o ./obj/Pixel.o

./obj/mainAffichage.o: ./src/mainAffichage.cpp ./src/Image.h ./src/Pixel.h
				g++ -g -Wall -c ./src/mainAffichage.cpp -o ./obj/mainAffichage.o		

clean:
		rm ./obj/*.o ./bin/*
