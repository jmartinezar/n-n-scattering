/* Headers */

#include <fstream>
#include <cmath>
#include "include.hpp"
#include <gsl/gsl_integration.h>

/* Main function */

int main(void)
{
  /* GSL declarations */
  gsl_integration_workspace *w = gsl_integration_workspace_alloc(1000);

  double result, error;

  double theta = 0.0;

  double k = 1.0;
  double q = 4*k*k*std::sin(theta/2.0)*std::sin(theta/2.0);

  gsl_function F;

  F.function = &f1;

  F.params = &q;

  /* Ofstream */
  
  std::ofstream output("4-1.txt", std::ofstream::out);

  /* Send data to output */

  output << "theta" << "\t" << "f(theta)\n";

  double dt = 2*M_PI/1000.0;
  
  for(int ii = 1; ii < 1000; ++ii)
    {
      gsl_integration_qagiu(&F, 0.0, 1e-10, 1e-4, 1000, w, &result, &error);
      output << theta << "\t" << result*result << "\n";
      theta = ii*dt;
      q = 4*k*k*std::sin(theta/2.0)*std::sin(theta/2.0);
    }

  gsl_integration_workspace_free(w);

  output.close();
  
  return 0;
}
