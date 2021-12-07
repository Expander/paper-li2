#include <math.h>

double li2(double x)
{
   const double PI = 3.1415926535897932;
   const double P[] = {
      1.0706105563309304277e+0,
     -4.5353562730201404017e+0,
      7.4819657596286408905e+0,
     -6.0516124315132409155e+0,
      2.4733515209909815443e+0,
     -4.6937565143754629578e-1,
      3.1608910440687221695e-2,
     -2.4630612614645039828e-4
   };
   const double Q[] = {
      1.0000000000000000000e+0,
     -4.5355682121856044935e+0,
      8.1790029773247428573e+0,
     -7.4634190853767468810e+0,
      3.6245392503925290187e+0,
     -8.9936784740041174897e-1,
      9.8554565816757007266e-2,
     -3.2116618742475189569e-3
   };

   double y = 0, r = 0, s = 1;

   /* transform to [0, 1/2) */
   if (x < -1) {
      const double l = log(1 - x);
      y = 1/(1 - x);
      r = -PI*PI/6 + l*(0.5*l - log(-x));
      s = 1;
   } else if (x == -1) {
      return -PI*PI/12;
   } else if (x < 0) {
      const double l = log1p(-x);
      y = x/(x - 1);
      r = -0.5*l*l;
      s = -1;
   } else if (x == 0) {
      return 0;
   } else if (x < 0.5) {
      y = x;
      r = 0;
      s = 1;
   } else if (x < 1) {
      y = 1 - x;
      r = PI*PI/6 - log(x)*log(1 - x);
      s = -1;
   } else if (x == 1) {
      return PI*PI/6;
   } else if (x < 2) {
      const double l = log(x);
      y = 1 - 1/x;
      r = PI*PI/6 - l*(log(1 - 1/x) + 0.5*l);
      s = 1;
   } else {
      const double l = log(x);
      y = 1/x;
      r = PI*PI/3 - 0.5*l*l;
      s = -1;
   }

   const double z = y - 0.25;
   const double z2 = z*z;
   const double z4 = z2*z2;
   const double p = P[0] + z * P[1]
      + z2 * (P[2] + z * P[3])
      + z4 * (P[4] + z * P[5]
              + z2 * (P[6] + z * P[7]));
   const double q = Q[0] + z * Q[1]
      + z2 * (Q[2] + z * Q[3])
      + z4 * (Q[4] + z * Q[5]
              + z2 * (Q[6] + z * Q[7]));

   return r + s*y*p/q;
}
