#include <cstdlib>
#include <iostream>
#include<ostream>
#include<cmath>
#include"bmp_io.hh"
#include"pixel.hh"
using namespace std;
int floor2(double x) {
	int y = (int) x;
	double z=y-x;
	if (abs(z) >= 0.5) {
  		return (y+1);
  	}
	if (abs(z) < 0.5) {
   		return y;
   	}
	return 0;
} 
int main(int argc, char **argv){
	if (argc <4) {
		clog << "Tu pensais vraiment que ça allait marcher ?"<< endl;
		return EXIT_FAILURE;
	}
	double std_ex_l=0;
	double mean_ex_l=0;
	double std_l=0;
	double mean_l=0;
	double M_l=0;
	double std_ex_a=0;
	double mean_ex_a=0;
	double std_a=0;
	double mean_a=0;
	double M_a=0;
	double std_ex_b=0;
	double mean_ex_b=0;
	double std_b=0;
	double mean_b=0;
	double M_b=0;

	// Peut être mettre tout ça dans une liste ?
	// Trois arguments, l'image d'entrée, l'image source et la sortie.
	Bmp24 source(argv[1]);
	size_t width_source=source.width();
  	size_t height_source=source.height();
  	unsigned char const * const source_data=source.pixel_data();
  	// On récupère la taille de l'image source et on met toutes les données dans un tableau.
	Bmp24 target(argv[2]);
	size_t width_target=target.width();
  	size_t height_target=target.height();
  	unsigned char const * const cible_target=target.pixel_data();
  	// On récupère les propriétées de l'image cible en couleur.
	Bmp24 output(width_source, height_source);
	unsigned char const * const output_data=output.pixel_data();
	// On crée une troisième image de la taille de l'image d'entrée qui sera l'image de sortie.
	for(size_t pixel_index=0 ; pixel_index<width_source*height_source;++pixel_index){
		pixel inter;
		unsigned char inter.tab[2][0]=source_data[3*pixel_index];
    	unsigned char inter.tab[1][0]=source_data[3*pixel_index+1];
    	unsigned char inter.tab[0][0]=source_data[3*pixel_index+2];
    	inter.LMS();
    	inter.LAB();
    	mean_ex_l=mean_ex_l+inter.tab[0][0];
    	mean_ex_a=mean_ex_a+inter.tab[1][0];
    	mean_ex_b=mean_ex_b+inter.tab[2][0];
    	//on calcule la variance à l'aide de l'algorithme de Welrod
    	double old_M_l = M_l;
    	M_l = M_l + (inter.tab[0][0]-M_l)/(pixel_index+1);
    	std_ex_l=std_ex_l + (inter.tab[0][0]-M_l)*(inter.tab[0][0]-old_M_l);
    	double old_M_a = M_a;
    	M_a = M_a + (inter.tab[1][0]-M_a)/(pixel_index+1);
    	std_ex_a=std_ex_a + (inter.tab[1][0]-M_a)*(inter.tab[1][0]-old_M_a);
    	double old_M_b = M_a;
    	M_a = M_a + (inter.tab[1][0]-M_a)/(pixel_index+1);
    	std_ex_a=std_ex_a + (inter.tab[1][0]-M_a)*(inter.tab[1][0]-old_M_a);
    	//puis mettre dans un objet pixel et appliquer les changements de bases et les stats.
	}
	mean_l=mean_ex_l/(width_source*height_source);
	mean_a=mean_ex_a/(width_source*height_source);
	mean_b=mean_ex_b/(width_source*height_source);
	std_l=std_ex_l/(width_source*height_source);
	std_a=std_ex_a/(width_source*height_source);
	std_b=std_ex_b/(width_source*height_source);

	mean_ex_l=0;
	mean_ex_a=0;
	mean_ex_b=0;
	std_ex_l=0;
	std_ex_a=0;
	std_ex_b=0;
	M_l=0;
	M_a=0;
	M_b=0;
	double mean_l_2=0;
	double mean_a_2=0;
	double mean_b_2=0;
	double std_l_2=0;
	double std_a_2=0;
	double std_b_2=0;

	for(size_t pixel_index=0 ; pixel_index<width_target*height_target;++pixel_index){
		pixel inter2;
		unsigned char inter2.tab[2][0]=target_data[3*pixel_index];
    	unsigned char inter2.tab[1][0]=target_data[3*pixel_index+1];
    	unsigned char inter2.tab[0][0]=target_data[3*pixel_index+2];
    	inter2.LMS();
    	inter2.LAB();
    	mean_ex_l=mean_ex_l+inter.tab[0][0];
    	mean_ex_a=mean_ex_a+inter.tab[1][0];
    	mean_ex_b=mean_ex_b+inter.tab[2][0];
    	//on calcule la variance à l'aide de l'algorithme de Welrod
    	double old_M_l = M_l;
    	M_l = M_l + (inter.tab[0][0]-M_l)/(pixel_index+1);
    	std_ex_l=std_ex_l + (inter.tab[0][0]-M_l)*(inter.tab[0][0]-old_M_l);
    	double old_M_a = M_a;
    	M_a = M_a + (inter.tab[1][0]-M_a)/(pixel_index+1);
    	std_ex_a=std_ex_a + (inter.tab[1][0]-M_a)*(inter.tab[1][0]-old_M_a);
    	double old_M_b = M_a;
    	M_a = M_a + (inter.tab[1][0]-M_a)/(pixel_index+1);
    	std_ex_a=std_ex_a + (inter.tab[1][0]-M_a)*(inter.tab[1][0]-old_M_a);
    	//puis mettre dans un objet pixel et appliquer les changements de bases et les stats.
	}
	mean_l_2=mean_ex_l/(width_source*height_source);
	mean_a_2=mean_ex_a/(width_source*height_source);
	mean_b_2=mean_ex_b/(width_source*height_source);
	std_l_2=std_ex_l/(width_source*height_source);
	std_a_2=std_ex_a/(width_source*height_source);
	std_b_2=std_ex_b/(width_source*height_source);

	for(size_t pixel_index=0 ; pixel_index<width_source*height_source;++pixel_index){
		pixel inter3;
		unsigned char inter3.tab[2][0]=source_data[3*pixel_index];
    	unsigned char inter3.tab[1][0]=source_data[3*pixel_index+1];
    	unsigned char inter3.tab[0][0]=source_data[3*pixel_index+2];
    	inter3.LMS();
    	inter3.LAB();
    	pixel inter4();
    	inter4.tab[0][0]=(std_l_2/std_l)*(inter3.tab[0][0] - mean_l) + mean_l_2;
    	inter4.tab[1][0]=(std_a_2/std_a)*(inter3.tab[1][0] - mean_a) + mean_a_2;
    	inter4.tab[2][0]=(std_b_2/std_b)*(inter3.tab[2][0] - mean_b) + mean_b_2;
    	inter4.back_to_LMS_from_LAB();
    	inter4.back_to_RGB_from_LMS();
    	output_data[3*pixel_index+2]=floor2(inter4.tab[0][0]);
    	output_data[3*pixel_index+1]=floor2(inter4.tab[1][0]);
    	output_data[3*pixel_index]=floor2(inter4.tab[2][0]);
	}
	bool ok = output.write_file(argv[3]);
	return (ok && cout.good()) ? EXIT_SUCCESS : EXIT_FAILURE;
}
