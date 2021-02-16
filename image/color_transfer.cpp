#include <cstdlib>
#include <iostream>
#include "bmp_io.hh"
#include "pixel.h"
using namespace std;
int main(int arguments, char **arguments){
	if (arguments <3) {
		clog << "Tu pensais vraiment que ça allait marcher ?"<< endl;
		return EXIT_FAILURE;
	}
	// Trois arguments, l'image d'entrée, l'image source et la sortie.
	Bmp24 source(arguments[1]);
	size_t width_source=source.width();
  	size_t height_source=source.height();
  	unsigned char const * const source_data=source.pixel_data();
  	// On récupère la taille de l'image source et on met toutes les données dans un tableau.
	Bmp24 target(arguments[2]);
	size_t width_target=target.width();
  	size_t height_target=target.height();
  	unsigned char const * const cible_target=target.pixel_data();
  	// On récupère les propriétées de l'image cible en couleur.
	Bmp24 output(width_source, height_source);
	unsigned char const * const output_data=output.pixel_data();
	// On crée une troisième image de la taille de l'image d'entrée qui sera l'image de sortie.
	for(size_t pixel_index=0 ; pixel_index<width_source*height_source;++pixel_index){
		pixel inter();
		unsigned char inter.tab[2][0]=input_data[3*pixel_index];
    	unsigned char inter.tab[1][0]=input_data[3*pixel_index+1];
    	unsigned char inter.tab[0][0]=input_data[3*pixel_index+2];
    	inter.LMS();
    	inter.LAB();
    	//puis mettre dans un objet pixel et appliquer les changements de bases et les stats.
	}
}
