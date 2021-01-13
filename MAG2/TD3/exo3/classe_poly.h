#ifndef classe_p_H
#define classe_p_H
#include<iostream>
using namespace std;
#include<vector>
class point
{
 private :
  double abs;
  double ord;
 public :
  double get_abs() const;
  double get_ord() const;
  void set_abs(double abs_);
  void set_ord(double ord_);
  void affiche();
  double module();
  point();
  point(double re_, double im_);
};
#endif

#ifndef classe_poly_H
#define classe_poly_H

class poly
{
 private :
  int ordre;
  point* mes_points;
 public :
  double get_ordre() const;
  void set_ordre(int ordre_);
  void set_mespoints(point* mes_points_);
  point get_mespoints() const;
  double coord();
  void poly_affiche();
  double perimetre();
  poly(int ordre_, vector<vector<double>> mes_points_);
};
#endif

