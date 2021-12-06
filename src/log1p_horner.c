double log1p_horner(double x) {
   return x*(1 + x*(-0.5 + x*(1./3
     + x*(-0.25 + x*(0.2
     + x*(-1./6 + x/7))))));
}
