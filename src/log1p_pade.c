double log1p_pade(double x) {
   const double num = 1 + 517208./718121*x +
      79040./2154363*x*x + 40./718121*x*x*x;
   const double den = 1 + 876192./718121*x +
      225120./718121*x*x + 640./718121*x*x*x;
   return x*num/den;
}
