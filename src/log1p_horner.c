double log1p_horner(double x) {
   return x*(1 + x*(-1./2 + x*(1./3
     + x*(-1./4 + x*(1./5
     + x*(-1./6 + 1./7*x))))));
}
