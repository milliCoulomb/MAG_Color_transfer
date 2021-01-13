#ifndef complexe_alea_H
#define complexe_alea_H
#include<iostream>
#include<ostream>
#include"complexe.h"
using namespace std;
class complexe_alea
{
 public:
  complexe_alea();
  virtual ~complexe_alea();
  void set_graine(unsigned int graine);
  int get_graine() const;
  virtual void initialise();
  virtual complexe valeur() const = 0;
 protected:
  unsigned int p_graine;
};
#endif
  
  
  
