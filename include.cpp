#include <cmath>
#include "include.hpp"

double V_R(double r)
{
  return V0R*std::exp(-kR*r*r);
}

double V_s(double r)
{
  return -V0s*std::exp(-ks*r*r);
}

double V_t(double r)
{
  return -V0t*std::exp(-kt*r*r);
}

double f1(double r, void *params)
{
  double q = *(double *)params;
  double factor = 2*mu1/(hbar*hbar);
  if(q == 0.0)
    return -factor*r*r*(V_R(r) + V_s(r));
  else
    return -factor*r*std::sin(r*q)*(V_R(r) + V_s(r))/q;
}

double f2(double r, void *params)
{
  double q = *(double *)params;
  double factor = 2*mu1/(hbar*hbar);
  if(q == 0.0)
    return -factor*r*r*(V_R(r) + V_t(r));
  else
    return -factor*r*std::sin(r*q)*(V_R(r) + V_t(r))/q;
}
