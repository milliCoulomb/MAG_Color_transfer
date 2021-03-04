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
  matrix(height_, width_)
{
  tab = new pixel*[height_];
  for (int i=0; i<height_; i++) {
    tab[i]= new pixel[width_];
  }
  for (int i=0; i<height_; i++){
    for (int j=0; j<width_; j++) {
      pixel chose;
    	tab[i][j]=chose;
      //tab[i][j].affiche();
    }
  }
  int j=0;
  int c=0;
  /*for (int i=0; i<height_*width_; i++) {
    pixel autre;
    autre.tab[0][0]=image_[3*i];
    autre.tab[1][0]=image_[3*i+1];
    autre.tab[2][0]=image_[3*i+2];
    if (i%(width_-1)==0){
      if (j<height_-1){
        j=j+1;
      }
      c=c+1;
      tab[j][0]=autre;
      cout << j << endl;
    }
    else {
      tab[j][int(i/(1+c*width_))]=autre;
    }

  }*/
  while (j<width_) {
    for (int i=0; i<height_; i++) {
      pixel autre;
      autre.tab[0][0]=image_[3*i+j*height_*3 +2];
      autre.tab[1][0]=image_[3*i+j*height_*3+1];
      autre.tab[2][0]=image_[3*i+j*height_*3];
      tab[i][j]=autre;
    }
    j=j+1;
  }
}
image::~image() {
  //for (int i=0; i<get_height(); i++) delete tab[i];
  //delete tab;
}
void image::go_to_LAB() const {
  for (int i=0; i<get_height(); i++) {
    for (int j=0; j<get_width(); j++) {
      tab[i][j].LMS();
      tab[i][j].LAB();
    }
  }
  cout << get_height() << endl;
  cout << get_width() << endl;
}
void image::go_to_RGB() const {
  for (int i=0; i<get_height(); i++) {
    for (int j=0; j<get_width(); j++) {
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
  for (int i=0; i<get_height(); i++) {
    for (int j=0; j<get_width(); j++) {
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
  for (int i=0; i<get_height(); i++) {
    for (int j=0; j<get_width(); j++) {
      red = red + tab[i][j].tab[0][0];
      green = green + tab[i][j].tab[1][0];
      blue = blue + tab[i][j].tab[2][0];
    }
  }
  red_mean=red/(get_width()*get_height());
  green_mean=green/(get_width()*get_height());
  blue_mean=blue/(get_width()*get_height());
  for (int i=0; i<get_height(); i++) {
    for (int j=0; j<get_width(); j++) {
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


