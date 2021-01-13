#ifndef classe_p_H
#define classe_p_H

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
