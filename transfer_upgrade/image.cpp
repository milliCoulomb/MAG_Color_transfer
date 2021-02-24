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
image::image(unsigned char const * const image_, size_t width_, size_t height_) :
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
  int j=0;
  int i_old=0;
  for (int i=i_old*3; i<3*3*width_*height_; i++) {
    pixel autre;
    if (i%3==0) {
      autre.tab[0][0]=image_[i];
      autre.tab[1][0]=image_[i+1];
      autre.tab[2][0]=image_[i+2];
      tab[i/3][j]=autre;
    }
    i_old=i+1;
    if (i%3*width==0 and i != 0){
      j=j+1;
    }
  }
}
image::~image() {
  for (int i=0; i<get_height(); i++) delete tab[i];
  delete tab;
}
void image::go_to_LAB() const {
  for (int i=0; i<get_width(); i++) {
    for (int j=0; j<get_height(); j++) {
      tab[i][j].LMS();
      tab[i][j].LAB();
    }
  }
}
void image::go_to_RGB() const {
  for (int i=0; i<get_width(); i++) {
    for (int j=0; j<get_height(); j++) {
      tab[i][j].back_to_LMS_from_LAB();
      tab[i][j].back_to_RGB_from_LMS();
    }
  }
}
pixel image::mean() const {
  pixel stat;
  double red = 0;
  double green = 0;
  double blue = 0;
  for (int i=0; i<get_width(); i++) {
    for (int j=0; j<get_height(); j++) {
      red = red + tab[i][j].tab[0][0];
      green = green + tab[i][j].tab[1][0];
      blue = blue + tab[i][j].tab[2][0];
    }
  }
  stat.tab[0][0]=red/(get_width()*get_height());
  stat.tab[1][0]=green/(get_width()*get_height());
  stat.tab[2][0]=blue/(get_width()*get_height());
  return stat;
}
pixel image::std() const {
  pixel stat;
  double red = 0;
  double green = 0;
  double blue = 0;
  double red_mean;
  double green_mean;
  double blue_mean;
  double red_std = 0;
  double green_std = 0;
  double blue_std = 0;
  for (int i=0; i<get_width(); i++) {
    for (int j=0; j<get_height(); j++) {
      red = red + tab[i][j].tab[0][0];
      green = green + tab[i][j].tab[1][0];
      blue = blue + tab[i][j].tab[2][0];
    }
  }
  red_mean=red/(get_width()*get_height());
  green_mean=green/(get_width()*get_height());
  blue_mean=blue/(get_width()*get_height());
  for (int i=0; i<get_width(); i++) {
    for (int j=0; j<get_height(); j++) {
      red_std = red_std + (tab[i][j].tab[0][0]-red_mean)*(tab[i][j].tab[0][0]-red_mean);
      green_std = green_std + (tab[i][j].tab[1][0]-green_mean)*(tab[i][j].tab[1][0]-green_mean);
      blue_std = blue_std + (tab[i][j].tab[2][0]-blue_mean)*(tab[i][j].tab[2][0]-blue_mean);
    }
  }
  stat.tab[0][0]=sqrt(red_std/(get_width()*get_height()));
  stat.tab[1][0]=sqrt(green_std/(get_width()*get_height()));
  stat.tab[2][0]=sqrt(blue_std/(get_width()*get_height()));
  return stat;
}


