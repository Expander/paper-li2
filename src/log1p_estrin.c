double log1p_estrin(double x) {
   const double y = x*x;
   const double z = y*y;
   return x + y*(1./3*x - 1./2) +
      z*(1./5*x - 1./4 + y*(-1./6 + 1./7*x));
}
