double log1p_naive(double x) {
   return x - x*x/2 + x*x*x/3 - x*x*x*x/4
      + x*x*x*x*x/5 - x*x*x*x*x*x/6
      + x*x*x*x*x*x*x/7;
}
