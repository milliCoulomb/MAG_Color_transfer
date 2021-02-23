#include<iostream>
#include<ostream>
#include"matrix.h"
#include"pixel.h"
using namespace std;
int image::get_width() const {
  return width;
}
int image::get_height() const {
  return height;
}
void image::set_width(int width_) {
  width=width_;
}
void image::set_height(int height_) {
  height=height_;
}
image::image(unsigned char const * const image_, int width_, int height_) :
  matrix(get_height(), get_width()), width(width_), height(height_), img(new pixel*[height])
{
  for (int i=0; i<height_; i++) {
    img[i]= new pixel[width_];
  }
  for (int i=0; i<height_; i++) {
    for (int j=0; j<width_; j++) {
    	img[i][j].tab[2][0]=double(image_[3*i*j]);
    	img[i][j].tab[1][0]=double(image_[3*i*j+1]);
    	img[i][j].tab[0][0]=double(image_[3*i*j+2]);
    }
  }
}
image::~image() {
  for (int i=0; i<get_height(); i++) delete img[i];
  delete img;
}

