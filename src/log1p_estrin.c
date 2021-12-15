double log1p_estrin(double x) {
   const double y = x*x;
   const double z = y*y;
   return x + (1./3*x - 1./2)*y
      + (y*(-1./6 + 1./7*x) + x/5 - 1./4)*z;
}
