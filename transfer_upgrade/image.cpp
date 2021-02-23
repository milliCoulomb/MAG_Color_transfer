#include<iostream>
#include<ostream>
#include"pixel.h"
#include"image.h"
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
image::image(int width_, int height_) :
  matrix(width_, height_), width(width_), height(height_), tab(new pixel*[width])
{
  for (int i=0; i<width_; i++) {
    tab[i]= new pixel[height_];
  }
  for (int i=0; i<width_; i++){
    for (int j=0; j<height_; j++) {
      pixel chose;
    	tab[i][j]=chose;
      //tab[i][j].affiche();
    }
  }
}
image::~image() {
  for (int i=0; i<get_height(); i++) delete tab[i];
  delete tab;
}

