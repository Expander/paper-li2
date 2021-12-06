double log1p_estrin(double x) {
   const double y = x*x;
   const double z = y*y;
   return x + (x/3 - 0.5)*y
      + (y*(-1./6 + x/7) + x/5 - 0.25)*z;
}
