#include <math.h>

double li2(double x)
{
   const double PI = 3.1415926535897932;
   const double P[] = {
      0.9999999999999999502e+0,
     -2.6883926818565423430e+0,
      2.6477222699473109692e+0,
     -1.1538559607887416355e+0,
      2.0886077795020607837e-1,
     -1.0859777134152463084e-2
   };
   const double Q[] = {
      1.0000000000000000000e+0,
     -2.9383926818565635485e+0,
      3.2712093293018635389e+0,
     -1.7076702173954289421e+0,
      4.1596017228400603836e-1,
     -3.9801343754084482956e-2,
      8.2743668974466659035e-4
   };

   double y = 0, r = 0, s = 1;

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

   const double y2 = y*y;
   const double y4 = y2*y2;
   const double p = P[0] + y * P[1]
      + y2 * (P[2] + y * P[3])
      + y4 * (P[4] + y * P[5]);
   const double q = Q[0] + y * Q[1]
      + y2 * (Q[2] + y * Q[3])
      + y4 * (Q[4] + y * Q[5] + y2 * Q[6]);

   return r + s*y*p/q;
}
