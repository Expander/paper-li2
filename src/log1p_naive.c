double log1p_naive(double x) {
   return x - 1./2*x*x + 1./3*x*x*x
      - 1./4*x*x*x*x + 1./5*x*x*x*x*x
      - 1./6*x*x*x*x*x*x + 1./7*x*x*x*x*x*x*x;
}
