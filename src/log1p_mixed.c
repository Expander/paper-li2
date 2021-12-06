double log1p_mixed(double x) {
   const double y = x*x;
   const double num = 1 + 517208./718121*x +
      y*(79040./2154363 + 40./718121*x);
   const double den = 1 + 876192./718121*x +
      y*(225120./718121 + 640./718121*x);
   return x*num/den;
}
