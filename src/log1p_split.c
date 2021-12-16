double log1p_split(double x) {
   const double y = x*x;
   return x*(1 + y*(1./3 + y*(1./5 + 1./7*y)))
      + y*(-1./2 + y*(-1./4 - 1./6*y));
}
