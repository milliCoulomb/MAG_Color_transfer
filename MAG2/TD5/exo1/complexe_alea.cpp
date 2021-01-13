#include "complexe.h"
#include"complexe_alea.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
complexe_alea::complexe_alea()
{
  p_graine=0;
}
complexe_alea::~complexe_alea()
{
}
void complexe_alea::set_graine(int graine)
{
  p_graine = graine;
}
int complexe_alea::get_graine() const;
{
  return p_graine;
}
void complexe_alea::initialise()
{
}
