double log1p_mixed(double x) {
   const double y = x*x;
   const double num = 1 + 51064./40143*x +
      y*(44320./120429 + 320./40143*x);
   const double den = 1 + 23712./13381*x +
      y*(12320./13381 + 5120./40143*x);
   return x*num/den;
}
