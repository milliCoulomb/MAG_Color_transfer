#include <iostream>
#include<ostream>
#include<cmath>
#include"bmp_io.hh"
#include"image.h"
using namespace std;

int main(int argc, char **argv){
	if (argc <4) {
		clog << "Tu pensais vraiment que ça allait marcher ?"<< endl;
		return EXIT_FAILURE;
	}
	Bmp24 source(argv[1]);
	size_t width_source=source.width();
  	size_t height_source=source.height();
  	unsigned char const * const source_data=source.pixel_data();
	Bmp24 target(argv[2]);
	size_t width_target=target.width();
  	size_t height_target=target.height();
  	unsigned char const * const target_data=target.pixel_data();
  	Bmp24 output(width_source, height_source);
	unsigned char * const output_data=output.pixel_data();
	image source1(source_data, width_source, height_source);
	image target1(target_data, width_target, height_target);
	target1.go_to_LAB();
	source1.go_to_LAB();
	pixel mean_source = source1.mean();
	pixel std_source = source1.std();
	pixel mean_target  = target1.mean();
	pixel std_target = target1.std();
	pixel inter;
	pixel inter_;
	unsigned char r;
    unsigned char b;
    unsigned char g;
	for(size_t pixel_index=0 ; pixel_index<width_source*height_source; pixel_index++){
		unsigned char red=source_data[3*pixel_index];
    	unsigned char green=source_data[3*pixel_index+1];
    	unsigned char blue=source_data[3*pixel_index+2];
    	inter.tab[2][0]=blue;
    	inter.tab[1][0]=green;
    	inter.tab[0][0]=red;
    	inter.LMS();
    	inter.LAB();
    	inter_.tab[0][0]=(std_target.tab[0][0]/std_source.tab[0][0])*(inter.tab[0][0] - mean_source.tab[0][0]);
    	inter_.tab[1][0]=(std_target.tab[1][0]/std_source.tab[1][0])*(inter.tab[1][0] - mean_source.tab[1][0]);
    	inter_.tab[2][0]=(std_target.tab[2][0]/std_source.tab[2][0])*(inter.tab[2][0] - mean_source.tab[2][0]);
    	inter_.back_to_LMS_from_LAB();
    	inter_.back_to_RGB_from_LMS();
    	r=round(inter_.tab[0][0]);
    	b=round(inter_.tab[2][0]);
    	g=round(inter_.tab[1][0]);
    	output_data[3*pixel_index+2]=b;
    	output_data[3*pixel_index+1]=g;
    	output_data[3*pixel_index]=r;
	}
	bool ok = output.write_file(argv[3]);
	return (ok && cout.good()) ? EXIT_SUCCESS : EXIT_FAILURE;
}
