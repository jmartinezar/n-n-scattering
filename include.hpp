#pragma once

/* Constants declaration */

#define V0R 200.0 /* MeV */
#define V0s 91.85 /* MeV */
#define V0t 178.0 /* MeV */

#define kR 1.487 /* fm^2 */
#define ks 0.465 /* fm^2 */
#define kt 0.639 /* fm^2 */

#define mu1 1.0 /**/
#define hbar 1.0 /**/

/* Functions declaration */

double V_R(double r);

double V_s(double r);

double V_t(double r);

double f1(double r, void *params);

double f2(double r, void *params);

double integral(double (*fun)(double), double xmin, double xmax, int N);
