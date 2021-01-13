#ifndef complexe_alea_uni_H
#define complexe_alea_uni_H
#include<iostream>
#include<ostream>
#include"complexe_alea.h"
using namespace std;
class complexe_alea_uni : public complexe_alea
{
 public:
  complexe_alea_uni(double v);
  ~complexe_alea_uni();
  void initialise() override;
  complexe valeur() const override;
  double get_lim() const;
  void set_lim(double v);
 private:
  double p_v;
};
#endif
